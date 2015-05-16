#include "Firefighter.hpp"

Firefighter::Firefighter(unsigned id, std::shared_ptr<Playground> playground,
                         std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen)
    : Person(id, playground, house, screen)
{}

void Firefighter::run()
{
    m_screen->refreshFirefighters(m_id, m_status);
    while (m_isRunning.load() == true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // TODO: Add a chance of dying
    }
}
