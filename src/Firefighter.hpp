#pragma once

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <memory>

#include "Playground.hpp"
#include "House.hpp"

class Firefighter
{
public:
    Firefighter(unsigned id, Playground* playground, House* house, OutputWindow* screen);
    ~Firefighter();

    void run();
    unsigned getId() const;
    std::string getStatus() const;

private:
    unsigned m_id;
    std::string m_status;
    bool m_isRunning;
    Playground* m_playground;
    House* m_house;
    OutputWindow* m_screen;
};
