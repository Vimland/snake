#include "UserInput.h"
std::condition_variable cv;

using namespace std;
UserInput::UserInput(){
    dir = UP;
}

void UserInput::getUserInput() {
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

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    cv.notify_one();
}

void UserInput::timedUserInput(){
    std::thread th (spawn());
    int threadAlive = 0; 
    std::mutex mtx;
    std::unique_lock<std::mutex> lck(mtx);
    while(cv.wait_for(lck, std::chrono::seconds(2)) == std::cv_status::timeout)
    {
        threadAlive = 1;
        ExitThread(th);
    } 
    if (threadAlive == 0)
        th.join(); 
}

std::thread UserInput::spawn(){
  return std::thread( [this] { this->getUserInput(); } );
}
Direction UserInput::getDirection(){
    return dir;
}
