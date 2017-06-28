#include <iostream>
#include "GameLogic.h"
#include "UserInput.h"
#include "enums.h"
#include <time.h>
#include <unistd.h>

int main()
{
 
// Intial constructor call
    GameLogic snake(10);  
	UserInput usr;

// Main Loop    
    while(1){
        usleep(200000);
        usr.getUserInput();
        std::pair<int, int> nextCoord = snake.getNextStep(usr.getDirection());
        snake.nextStep(nextCoord);
        snake.updateBoard();
        snake.paint();
    }
    return 0;

}
