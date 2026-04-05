#include "common.hpp"
#include <cmath>
#include <algorithm>

class CA_Simulator{
    public:
      CellState grid[GRID_H][GRID_W];
      int staticField[GRID_H][GRID_W]; //Сетка расстояний
      
      float CalTransitionProb(int x, int y, int targetX, int targetY, Vec2 lastMove, const CA_Params& params){
    
    if(grid[targetY][targetX] != CellState::Empty && grid[targetY][targetX] != CellState::Exit )
      return 0.0f;
    
    float S = static_cast<float>(staticField[targetY][targetX]);
    
    float staticWeight = std::exp(-params.kStatic * S);
    
    Vec2 currentMove(targetX - x, targetY - y); 

    float inertiaWeight = (currentMove == lastMove) ? params.kInertia : 1.0f;
    
    return staticWeight * inertiaWeight;
 }
};
