#pragma once

class Playground
{
public:
    Playground(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets,
               unsigned numOfMatches, unsigned numOfFuel);

private:
    volatile unsigned m_hatchets;
    volatile unsigned m_firehoses;
    volatile unsigned m_helmets;
    volatile unsigned m_matches;
    volatile unsigned m_fuel;
};
