#include "GameLogic.h"

// Empty constructor
GameLogic::GameLogic(){
}

// Initializes the board
GameLogic::GameLogic(int x){
    srand (time(NULL));
    size = x;
    snake.push_back(getRandomCoord());
    for(int i = 0; i < size; i++){
        board.push_back(std::vector<std::string> ());
        for(int j = 0; j< size; j++){
            board.at(i).push_back(" ");  
          }
     }
    setNewApple();
    updateBoard();
    paint();
}

void GameLogic::setNewApple(){
    for(int i = 0; i < snake.size(); i++)
    {
        board.at(snake.at(i).first).at(snake.at(i).second) = "+";
    }
    std::pair<int, int> potentialApple = getRandomCoord();
    while(board.at(potentialApple.first).at(potentialApple.second) == "+"){
        potentialApple = getRandomCoord();
    }
    apple=potentialApple;
}

// Simply paints the board to stdout.
void GameLogic::paint(){
    for (int i = 0; i < size; i++){
       for(int j = 0; j < size; j++){
           std::cout << board.at(i).at(j);
       }
     std::cout << std::endl;
     }
}

// Generates aple ToDo rework generate a new pair within board.
std::pair<int, int> GameLogic::getRandomCoord(){
    int first = rand() % (size-2)+1;
    int second = rand() % (size-2)+1;
    return std::pair<int, int>(first, second);
}

//Updates board, snake and apple after previous iteration.
void GameLogic::updateBoard(){
// Re-insert empty board
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
         
            if(i == 0 || i == size-1)
                board.at(i).at(j)="#";
          
            else if (j == 0 || j==size-1)
                board.at(i).at(j)="#";
            else board.at(i).at(j) = " ";
            }
      }

// Insert apple to board
    board.at(apple.first).at(apple.second) = "0"; 

// Insert snake to board
        for(int i = 0; i < snake.size(); i++){
            board.at(snake.at(i).first).at(snake.at(i).second) = "+";   
     }
}

// ToDO Update snake position after each iteration
void GameLogic::moveSnake(std::pair<int, int> newHead){
    for(int i = 1; i < snake.size(); i++) {
       snake.at(snake.size()-i) = snake.at(snake.size()-i-1);
    }
    snake.at(0) = newHead;      
}

// Checks if collision or if apple is taken. ToDo: Add pixel to snake if apple is taken
void GameLogic::nextStep(std::pair<int, int> nextStep){
    std::string symbol = board.at(nextStep.first).at(nextStep.second);
    std::cout << symbol << std::endl; 

    if(symbol == "#" || symbol == "+")
        exit (EXIT_FAILURE);
    
    else if(symbol == "0") {
         snake.insert(snake.begin(), nextStep);
         setNewApple();
    }
    else moveSnake(nextStep);
}

std::pair<int, int> GameLogic::getNextStep(Direction dir){
   std::pair<int, int> nextStepCoord (snake.at(0).first, snake.at(0).second);

    switch (dir) {
        case UP:
           nextStepCoord.first -= 1;
           break;

        case DOWN:
           nextStepCoord.first += 1;
           break;
        
        case LEFT:
           nextStepCoord.second -= 1;
           break;
 
        case RIGHT:
           nextStepCoord.second += 1;
           break;
    }
    return nextStepCoord;
}
