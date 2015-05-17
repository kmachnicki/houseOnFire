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
        updateStatus("Acquiring tools");

        // TODO: Get resources...

        bool workDone;
        while (m_isRunning.load() == true)
        {
            updateStatus("Getting inside...");
            workDone = m_house->ignite(this);
            if (workDone == true)
            {
                break;
            }
            else
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(m_spawnTimeInMs(m_randomGenerator)));
            }
        }
        updateStatus("Releasing tools");

        // TODO: Release resources...

        updateStatus("Gonna rest");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000 + m_spawnTimeInMs(m_randomGenerator)));
    }
    updateStatus("Killing myself");
}

void Arsonist::updateStatus(const std::string& newStatus)
{
    Person::updateStatus(newStatus);
    m_screen->refreshArsonists(m_id, m_status);
}
