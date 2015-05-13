#pragma once

#include <sstream>
#include <thread>
#include <mutex>

class Firefighter
{
public:
    Firefighter();
    ~Firefighter();

    void run();
    std::string getCurrentStatus();
};
