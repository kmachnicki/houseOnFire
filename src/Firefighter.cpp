#include "Firefighter.hpp"

Firefighter::Firefighter(unsigned id, std::shared_ptr<Playground> playground,
                         std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen)
    : Person(id, playground, house, screen)
{
    m_screen->refreshFirefighters(m_id, m_status);
}

void Firefighter::run()
{
    while (m_isRunning.load() == true)
    {
        updateStatus("Acquiring tools");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 + m_spawnTimeInMs(m_randomGenerator)));

        auto startTime = std::chrono::high_resolution_clock::now();
        bool hasHatchet = false, hasFirehose = false, hasHelmet = false;
        while((hasHatchet != true) && (hasFirehose != true) && (hasHelmet != true))
        {
            if (m_isRunning.load() == false)
            {
                updateStatus("Killing myself");
                return;
            }

            hasHatchet = m_playground->acquireHatchet();
            hasFirehose = m_playground->acquireFirehose();
            hasHelmet = m_playground->acquireHelmet();
            std::this_thread::sleep_for(std::chrono::milliseconds(m_spawnTimeInMs(m_randomGenerator)));
            auto stopTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> elapsedTime = stopTime - startTime;
            if (elapsedTime.count() > 4000)
            {
                if (hasHatchet == true)
                {
                    m_playground->storeHatchet();
                    hasHatchet = false;
                }
                if (hasFirehose == true)
                {
                    m_playground->storeFirehose();
                    hasHatchet = false;
                }
                if (hasHelmet == true)
                {
                    m_playground->storeHelmet();
                    hasHatchet = false;
                }
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
            workDone = m_house->extinguish(this);
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

        m_playground->storeHatchet();
        m_playground->storeFirehose();
        m_playground->storeHelmet();

        updateStatus("Gonna rest");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000 + m_spawnTimeInMs(m_randomGenerator)));
    }
    updateStatus("Killing myself");
}

void Firefighter::updateStatus(const std::string& newStatus)
{
    Person::updateStatus(newStatus);
    m_screen->refreshFirefighters(m_id, m_status);
}
