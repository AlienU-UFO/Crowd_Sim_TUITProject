//Графический интерфейс
#ifndef GUI_HPP
#define GUI_HPP
#include "common.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <string>

struct Button {
    sf::RectangleShape shape;
    sf::Text text;
    std::function<void()> action;

    Button(std::string label, sf::Vector2f pos, sf::Vector2f size, sf::Font& font, std::function<void()> onClick) 
    : action(onClick), text(font)
{
    shape.setPosition(pos);
    shape.setSize(size);
    shape.setFillColor(sf::Color(70, 70, 70));
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::White);

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    
    sf::FloatRect textRect = text.getLocalBounds();
    
    text.setOrigin({
        textRect.position.x + textRect.size.x / 2.0f, 
        textRect.position.y + textRect.size.y / 2.0f
    });

    text.setPosition({
        pos.x + size.x / 2.0f, 
        pos.y + size.y / 2.0f
    });
}

    bool isClicked(sf::Vector2i mousePos) const {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    void updateHover(sf::Vector2i mousePos) {
        if (isClicked(mousePos)) shape.setFillColor(sf::Color(100, 100, 100));
        else shape.setFillColor(sf::Color(70, 70, 70));
    }
};




class Menu {
private:
    std::vector<Button> buttons;
    sf::Font font;

public:
    enum class State { MainMenu, Editor, Simulation, Exit };
    State currentState = State::MainMenu;

    Menu() {
        if (!font.openFromFile("resources/arial.ttf")) { /* Ошибка */ }

        float btnW = 250;
        float btnH = 50;
        float centerX = 400 - btnW / 2; // Центр при окне 800x600

        buttons.emplace_back("Start Simulation", sf::Vector2f(centerX, 200), sf::Vector2f(btnW, btnH), font, 
            [&]() { currentState = State::Simulation; });

        buttons.emplace_back("Create Level", sf::Vector2f(centerX, 270), sf::Vector2f(btnW, btnH), font, 
            [&]() { currentState = State::Editor; });

        buttons.emplace_back("Exit", sf::Vector2f(centerX, 340), sf::Vector2f(btnW, btnH), font, 
            [&]() { currentState = State::Exit; });
    }

    void handleEvent(const sf::Event& event, sf::RenderWindow& window) {
        if (auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseEvent->button == sf::Mouse::Button::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& btn : buttons) {
                    if (btn.isClicked(mousePos)) btn.action();
                }
            }
        }
    }

    void update(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (auto& btn : buttons) btn.updateHover(mousePos);
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& btn : buttons) {
            window.draw(btn.shape);
            window.draw(btn.text);
        }
    }
};

#endif



