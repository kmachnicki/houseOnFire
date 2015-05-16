#include "Playground.hpp"

Playground::Playground(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets,
                       unsigned numOfMatches, unsigned numOfFuel)
    : m_hatchets(numOfHatchets)
    , m_firehoses(numOfFirehoses)
    , m_helmets(numOfHelmets)
    , m_matches(numOfMatches)
    , m_fuel(numOfFuel)
{}
