#include "FireSimulator.hpp"

FireSimulator::FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                             unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize)
    : m_firefighters(numOfFirefighters)
    , m_arsonists(numOfArsonists)
    , m_hatchets(numOfHatchets)
    , m_firehoses(numOfFirehoses)
    , m_helmets(numOfHelmets)
    , m_initialFireSize(initialFireSize)
{}

void FireSimulator::run()
{
    for (unsigned i = 0; i < m_firefighters.size(); ++i)
    {
        m_firefighters[i] = std::move(std::thread(&Firefighter::run, new Firefighter()));
    }

    for (unsigned i = 0; i < m_arsonists.size(); ++i)
    {
        m_arsonists[i] = std::move(std::thread(&Arsonist::run, new Arsonist()));
    }

    for (auto& firefighter : m_arsonists)
    {
        firefighter.join();
    }

    for (auto& arsonist : m_arsonists)
    {
        arsonist.join();
    }
}
