#ifndef USERINPUT_H
#define USERINPUT_H
#include <stdio.h>
#include "enums.h"
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class UserInput {

    public:
        UserInput();
        void getUserInput();
        Direction getDirection();
        void timedUserInput();
        std::thread spawn();
    private:
        Direction dir;
};

#endif
