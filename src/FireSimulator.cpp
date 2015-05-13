#include "FireSimulator.hpp"

FireSimulator::FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                             unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize)
    : m_firefighters(numOfFirefighters)
    , m_arsonists(numOfArsonists)
    , m_playground(std::make_shared<Playground>(numOfHatchets, numOfFirehoses, numOfHelmets))
    , m_house(std::make_shared<House>(initialFireSize))
{}

void FireSimulator::run()
{
    for (unsigned i = 0; i < m_firefighters.size(); ++i)
    {
        m_firefighters[i] = std::move(std::thread(&Firefighter::run, new Firefighter(i, m_playground, m_house)));
    }

    for (unsigned i = 0; i < m_arsonists.size(); ++i)
    {
        m_arsonists[i] = std::move(std::thread(&Arsonist::run, new Arsonist(i, m_playground, m_house)));
    }

    for (auto& firefighter : m_firefighters)
    {
        firefighter.join();
    }

    for (auto& arsonist : m_arsonists)
    {
        arsonist.join();
    }
}
