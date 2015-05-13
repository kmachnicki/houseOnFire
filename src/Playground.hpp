#pragma once

class Playground
{
public:
    Playground(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets);

private:
    volatile unsigned m_hatchets;
    volatile unsigned m_firehoses;
    volatile unsigned m_helmets;
};
