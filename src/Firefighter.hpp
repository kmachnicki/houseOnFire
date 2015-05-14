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
    Firefighter(unsigned id, std::shared_ptr<Playground> playground, std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen);
    ~Firefighter();

    void run();
    unsigned getId() const;
    std::string getStatus() const;

private:
    unsigned m_id;
    std::string m_status;
    bool m_isRunning;
    std::shared_ptr<Playground> m_playground;
    std::shared_ptr<House> m_house;
    std::shared_ptr<OutputWindow> m_screen;
};
