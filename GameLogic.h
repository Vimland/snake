#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <utility> 
#include <string>

class GameLogic {
 private:
  std::vector<std::vector<std::string>> board;
  std::vector<std::pair<int, int>> snake;
  int size;
  std::pair<int,int> apple;
//  enum dir{"UP", "DOWN", "LEFT", "RIGHT"};

 public:
  GameLogic();  
  GameLogic(int x);
  void paint();
  void moveSnake();
  void nextStep(std::pair<int,int> step);
  void updateBoard();
  void newApple();

};
#endif
