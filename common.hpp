//Необходимые переменные и структуры
#ifndef COMMON_HPP
#define COMMON_HPP

#include <SFML/System/Vector2.hpp>
#include <vector>

const int GRID_W = 40;
const int GRID_H = 30;
const float CELL_SIZE = 20.f;
const int INF = 1e6;

enum class CellState {
    Empty, Wall, Exit, Occupied, Spawn
};

struct CA_Params{
    float kStatic = 3.0f;
    float kInertia = 1.5f;
};

struct Vec2{
    int x;
    int y;
    Vec2(int a, int b) : x(a), y(b){}
    bool operator==(const Vec2& other) const
      {return (this -> x == other.x && this -> y == other.y); }
    Vec2 operator+(const Vec2& other)
      {return Vec2(this -> x + other.x, this -> y + other.y);}
    Vec2 operator-(const Vec2& other)
      {return Vec2(this -> x - other.x, this -> y - other.y);}
};

#endif // !COMMON_HPP

