#pragma once

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <memory>

//#include "Playground.hpp"
//#include "House.hpp"

class Arsonist
{
public:
    Arsonist(unsigned id);//, std::shared_ptr<Playground> playground, std::shared_ptr<House> house);
    ~Arsonist();

    void run();
    unsigned getId() const;
    std::string getStatus() const;

private:
    unsigned m_id;
    bool m_isRunning;
    //std::shared_ptr<Playground> m_playground;
    //std::shared_ptr<House> m_house;
};
