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
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 + m_spawnTimeInMs(m_randomGenerator)));

        auto startTime = std::chrono::high_resolution_clock::now();
        bool hasMatches = false, hasFuel = false;
        while((hasMatches != true) && (hasFuel != true))
        {
            if (m_isRunning.load() == false)
            {
                updateStatus("Killing myself");
                return;
            }

            hasMatches = m_playground->acquireMatch();
            hasFuel = m_playground->acquireFuel();
            std::this_thread::sleep_for(std::chrono::milliseconds(m_spawnTimeInMs(m_randomGenerator)));
            auto stopTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsedTime = stopTime - startTime;
            if (elapsedTime.count() > 4000)
            {
                updateStatus("Releasing tools...");
                if (hasMatches == true)
                {
                    m_playground->storeMatch();
                    hasMatches = false;
                }
                if (hasFuel == true)
                {
                    m_playground->storeFuel();
                    hasFuel = false;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(m_spawnTimeInMs(m_randomGenerator)));
            }
        }

        bool workDone;
        while (true)
        {
            if (m_isRunning.load() == false)
            {
                updateStatus("Killing myself");
                return;
            }

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
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 + m_spawnTimeInMs(m_randomGenerator)));

        m_playground->storeMatch();
        m_playground->storeFuel();

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
