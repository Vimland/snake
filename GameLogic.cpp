#include "GameLogic.h"

GameLogic::GameLogic(){
}

GameLogic::GameLogic(int x){
  size = x;
  newApple();
  srand(time(NULL));
  snake.push_back(std::pair<int,int>(rand() % (size-2)+1,rand() % (size-2)+1));
  for(int i = 0; i < size; i++){
    board.push_back(std::vector<std::string> ());
    for(int j = 0; j< size; j++){
      board.at(i).push_back(" ");  
    }
  }
}

void GameLogic::paint(){
  for (int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      std::cout << board.at(i).at(j);
    }
    std::cout << std::endl;
  }
}

void GameLogic::newApple(){
  srand (time(NULL));
  apple.first = rand() % (size-2)+1;
  apple.second = rand() % (size-2)+1;
}

void GameLogic::updateBoard(){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
     
      if(i == 0 || i == size-1)
        board.at(i).at(j)="#";
      
      else if (j == 0 || j==size-1)
        board.at(i).at(j)="#";
    }
  }
  board.at(apple.first).at(apple.second) = "0"; 
  for(int i = 0; i < snake.size(); i++){
    board.at(snake.at(i).first).at(snake.at(i).second) = "+";   
  }
}

void GameLogic::moveSnake(){

}

void GameLogic::nextStep(std::pair<int,int> step){
  std::string symbol = board.at(step.first).at(step.second);
  
  if(symbol == "#" || symbol == "+")
    exit (EXIT_FAILURE);

  else if(symbol == "0")
    newApple();
}
