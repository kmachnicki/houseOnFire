#include "FireSimulator.hpp"

FireSimulator::FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                             unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize)
    : m_firefighters(numOfFirefighters)
    , m_arsonists(numOfArsonists)
    , m_playground(new Playground(numOfHatchets, numOfFirehoses, numOfHelmets))
    , m_screen(new OutputWindow())
    , m_house(new House(initialFireSize, m_screen))
{}

void FireSimulator::run()
{
    m_screen->refreshHouse(53);
    for (unsigned i = 0; i < m_firefighters.size(); ++i)
    {
        //m_screen->refreshFirefighters(i, "sdf");
        //m_firefighters[i] = std::move(std::thread(&Firefighter::run, new Firefighter(i, m_playground, m_house, m_screen)));
    }

    for (unsigned i = 0; i < m_arsonists.size(); ++i)
    {
        //m_screen->refreshArsonists(i, "xxxx");
        //m_arsonists[i] = std::move(std::thread(&Arsonist::run, new Arsonist(i, m_playground, m_house, m_screen)));
    }

    /*for (auto& firefighter : m_firefighters)
    {
        firefighter.join();
    }

    for (auto& arsonist : m_arsonists)
    {
        arsonist.join();
    }*/
    usleep(3000);
    delete m_playground;
    delete m_house;
    delete m_screen;
}
