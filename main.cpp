#include <iostream>
#include "GameLogic.h"
#include "UserInput.h"
#include "enums.h"
#include <time.h>

int main()
{
 
// Intial constructor call
    GameLogic snake(10);  
	UserInput usr;

// Main Loop    
//	getUserInput();
    while(1){
        usr.timedUserInput();
        std::pair<int, int> nextCoord = snake.getNextStep(usr.getDirection());
        snake.nextStep(nextCoord);
        snake.updateBoard();
        snake.paint();
        int usleep(2000);
    }
    return 0;

}
