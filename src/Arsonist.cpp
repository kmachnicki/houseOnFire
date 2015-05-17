#include "Arsonist.hpp"

Arsonist::Arsonist(unsigned id, std::shared_ptr<Playground> playground,
                   std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen)
    : Person(id, playground, house, screen)
{
    m_screen->refreshArsonists(m_id, m_status);
}

void Arsonist::run()
{
    while (m_isRunning.load() == true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        updateStatus("Getting inside...");
        m_house->ignite(this);
        updateStatus("Gonna sleep");
    }
    updateStatus("Killing myself");
}

void Arsonist::updateStatus(const std::string& newStatus)
{
    Person::updateStatus(newStatus);
    m_screen->refreshArsonists(m_id, m_status);
}
