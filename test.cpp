#include <iostream>
#include <ncurses.h>

using namespace std;
void foo(){
cout "Hejsan" << endl;
}
int main()
{
    WINDOW *w;
    w = initscr();
    char c;
    timeout(3000);
    endwin();
    cout << c << endl;
    return 0;
}
