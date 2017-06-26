#include <iostream>
#include "GameLogic.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int main()
{
    using namespace std;
    struct termios old_tio, new_tio;
    unsigned char c;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    enum Direction {UP, DOWN, LEFT, RIGHT};
    Direction dir = UP;
    do {
        c=getchar();
        
        switch (c){
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;    
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        }
        
    cout << "dir = " << dir << endl;
    } while(c!='q');

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    

    GameLogic snake(10);  
    snake.updateBoard();
    snake.paint();
    return 0;

}
