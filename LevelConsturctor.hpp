//Первая строка Ширина Высота
//Расширение файла .lvl - level.lvl
//E - выход S - спавн # - стена . - пусто
//Пример:
//
//20 10
//####################
//# S    #           #
//#     #            #
//#      #           #
//#     #            #
//#    #             #
//#   #              #
//#                  #
//#                  #
//#               E  #
//####################

#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include "common.hpp"
#include <SFML/Graphics.hpp>

class LevelManager {
public:
    static bool saveLevel(const std::string filename, const std::vector<std::vector<CellState>> & grid){
        
      if(!std::filesystem::exists("levels")){
          std::filesystem::create_directory("levels");
    }
      std::string fullPath = "levels/" + filename + ".lvl";
        std::ofstream outFile(fullPath);

        if (!outFile.is_open()) {
            std::cerr << "Error: Could not save file " << fullPath << std::endl;
            return false;
        }
  }
};

#endif
