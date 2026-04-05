#include "common.hpp"
#include "GUI.hpp"
#include "LevelConsturctor.hpp"
#include "Simulation.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Crowd Simulator");
    Menu menu;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();

            if (menu.currentState == Menu::State::MainMenu) {
                menu.handleEvent(*event, window);
            }
            // Здесь добавить обработку событий для Editor или Simulation
        }

        if (menu.currentState == Menu::State::Exit) window.close();

        window.clear();

        if (menu.currentState == Menu::State::MainMenu) {
            menu.update(window);
            menu.draw(window);
        } else if (menu.currentState == Menu::State::Editor) {
            // Отрисовка конструктора уровней
        } else if (menu.currentState == Menu::State::Simulation) {
            // Отрисовка симуляции
        }

        window.display();
    }
    return 0;
}
