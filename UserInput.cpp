#include "UserInput.h"
#include <ncurses.h>
std::condition_variable cv;

using namespace std;
UserInput::UserInput(){
    dir = UP;
}

void UserInput::getUserInput() {
    using namespace std;
    struct termios old_tio, new_tio;
    WINDOW *w;
    w = initscr();
    nodelay(w, true);
    noecho();
    char c;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

        c=getch();
                
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

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    endwin();
}


Direction UserInput::getDirection(){
    return dir;
}
