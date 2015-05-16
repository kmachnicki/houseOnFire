#include "Playground.hpp"

Playground::Playground(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets,
                       unsigned numOfMatches, unsigned numOfFuel, std::shared_ptr<OutputWindow> screen)
    : m_hatchets(numOfHatchets)
    , m_firehoses(numOfFirehoses)
    , m_helmets(numOfHelmets)
    , m_matches(numOfMatches)
    , m_fuel(numOfFuel)
    , m_screen(screen)
{
    m_screen->refreshResources(m_hatchets, m_firehoses, m_helmets, m_matches, m_fuel);
}
