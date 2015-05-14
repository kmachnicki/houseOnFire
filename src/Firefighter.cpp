#include "Firefighter.hpp"

Firefighter::Firefighter(unsigned id, Playground* playground, House* house, OutputWindow* screen)
    : m_id(id)
    , m_status("Waiting")
    , m_isRunning(true)
    , m_playground(playground)
    , m_house(house)
    , m_screen(screen)
{}

Firefighter::~Firefighter()
{}

void Firefighter::run()
{
    m_screen->refreshFirefighters(m_id, m_status);
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
    return m_status;
}
