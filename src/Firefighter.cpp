#include "Firefighter.hpp"

Firefighter::Firefighter(unsigned id)//, std::shared_ptr<Playground> playground, std::shared_ptr<House> house)
    : m_id(id)
    , m_isRunning(true)
    /*, m_playground(playground)
    , m_house(house)*/
{}

Firefighter::~Firefighter()
{}

void Firefighter::run()
{
    while (m_isRunning)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        m_isRunning = false;
        // TODO: Add a chance of dying
    }
}

unsigned Firefighter::getId() const
{
    return m_id;
}

std::string Firefighter::getStatus() const
{
    return "x";
}
