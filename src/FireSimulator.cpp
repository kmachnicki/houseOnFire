#include "FireSimulator.hpp"

FireSimulator::FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                             unsigned numOfFirehoses, unsigned numOfHelmets, unsigned numOfMatches,
                             unsigned numOfFuel, unsigned initialFireSize)
    : m_firefighters(numOfFirefighters)
    , m_arsonists(numOfArsonists)
    , m_screen(std::make_shared<OutputWindow>())
    , m_house(std::make_shared<House>(initialFireSize, m_screen))
    , m_playground(std::make_shared<Playground>(numOfHatchets, numOfFirehoses, numOfHelmets, numOfMatches, numOfFuel, m_screen))
{}

void FireSimulator::run()
{
    for (unsigned i = 0; i < m_firefighters.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(m_spawnTimeInMs(m_randomGenerator)));
        std::shared_ptr<Firefighter> firefighter = std::make_shared<Firefighter>(i + 1, m_playground, m_house, m_screen);
        m_firefighters[i] = std::make_tuple(firefighter, std::move(std::thread(&Firefighter::run, firefighter)));
    }

    for (unsigned i = 0; i < m_arsonists.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(m_spawnTimeInMs(m_randomGenerator)));
        std::shared_ptr<Arsonist> arsonist = std::make_shared<Arsonist>(i + 1, m_playground, m_house, m_screen);
        m_arsonists[i] = std::make_tuple(arsonist, std::move(std::thread(&Arsonist::run, arsonist)));
    }

    auto tasksKiller = std::async(std::launch::async, [&](){ waitForSignalAndKillTasks(); });
    tasksKiller.get();
    endwin();
}

void FireSimulator::waitForSignalAndKillTasks()
{
    while (true)
    {
        if ('q' == getchar())
        {
            for (auto& firefighter : m_firefighters)
            {
                std::get<0>(firefighter)->kill();
            }

            for (auto& arsonist : m_arsonists)
            {
                std::get<0>(arsonist)->kill();
            }

            for (auto& firefighter : m_firefighters)
            {
                std::get<1>(firefighter).join();
            }

            for (auto& arsonist : m_arsonists)
            {
                std::get<1>(arsonist).join();
            }
            break;
        }
    }
}
