#include "Arsonist.hpp"

Arsonist::Arsonist(unsigned id, std::shared_ptr<Playground> playground, std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen)
    : m_id(id)
    , m_status("Waiting")
    , m_isRunning(true)
    , m_playground(playground)
    , m_house(house)
    , m_screen(screen)
{}

Arsonist::~Arsonist()
{}

void Arsonist::run()
{
    m_screen->refreshArsonists(m_id, m_status);
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
