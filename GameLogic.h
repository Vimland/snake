#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "UserInput.h"
#include "enums.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <utility> 
#include <string>

class GameLogic {
 private:
  std::vector<std::vector<std::string> > board;
  std::vector<std::pair<int, int> > snake;
  int size;
  std::pair<int,int> apple;

 public:
  GameLogic();  
  GameLogic(int x);

  void paint();
  void moveSnake(std::pair<int, int> newHead);
  void nextStep(std::pair<int, int> nextStep);
  void updateBoard();
  void setNewApple();
  std::pair<int, int> getRandomCoord();
  std::pair<int, int> getNextStep(Direction dir); 

};
#endif
