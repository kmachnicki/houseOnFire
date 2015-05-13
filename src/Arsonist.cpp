#include "Arsonist.hpp"

Arsonist::Arsonist(unsigned id, std::shared_ptr<Playground> playground, std::shared_ptr<House> house)
    : m_id(id)
    , m_status("Waiting")
    , m_isRunning(true)
    , m_playground(playground)
    , m_house(house)
{}

Arsonist::~Arsonist()
{}

void Arsonist::run()
{
    Screen.refreshArsonists(m_id, m_status);
    while (m_isRunning)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        m_isRunning = false;
        // TODO: Add a chance of dying
    }
}

unsigned Arsonist::getId() const
{
    return m_id;
}

std::string Arsonist::getStatus() const
{
    return m_status;
}
