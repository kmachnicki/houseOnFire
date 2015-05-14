#include "FireSimulator.hpp"

FireSimulator::FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                             unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize)
    : m_firefighters(numOfFirefighters)
    , m_arsonists(numOfArsonists)
    , m_playground(std::make_shared<Playground>(numOfHatchets, numOfFirehoses, numOfHelmets))
    , m_screen(std::make_shared<OutputWindow>())
    , m_house(std::make_shared<House>(initialFireSize, m_screen))
{}

void FireSimulator::run()
{

    m_screen->refreshResources(4, 6, 6, 7, 8);
    m_screen->refreshHouse(53);
    for (unsigned i = 0; i < m_firefighters.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m_screen->refreshFirefighters(i, "sdf");
        //m_firefighters[i] = std::move(std::thread(&Firefighter::run, new Firefighter(i, m_playground, m_house, m_screen)));
    }

    for (unsigned i = 0; i < m_arsonists.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m_screen->refreshArsonists(i, "xxxx");
        //m_arsonists[i] = std::move(std::thread(&Arsonist::run, new Arsonist(i, m_playground, m_house, m_screen)));
    }
m_screen->refreshHouse(51);
    /*for (auto& firefighter : m_firefighters)
    {
        firefighter.join();
    }

    for (auto& arsonist : m_arsonists)
    {
        arsonist.join();
    }*/
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
