#pragma once

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>

class Arsonist
{
public:
    Arsonist();
    ~Arsonist();

    void run();
    std::string getCurrentStatus();
};
