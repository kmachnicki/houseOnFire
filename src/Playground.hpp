#pragma once

#include "OutputWindow.hpp"

class Playground
{
public:
    Playground(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets,
               unsigned numOfMatches, unsigned numOfFuel, std::shared_ptr<OutputWindow> screen);

private:
    volatile unsigned m_hatchets;
    volatile unsigned m_firehoses;
    volatile unsigned m_helmets;
    volatile unsigned m_matches;
    volatile unsigned m_fuel;

    std::shared_ptr<OutputWindow> m_screen;
};
