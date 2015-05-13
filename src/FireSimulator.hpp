#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>
#include <mutex>
#include <atomic>
#include <cassert>
#include <queue>
#include <condition_variable>

#include "Arsonist.hpp"
#include "Firefighter.hpp"

class FireSimulator
{
public:
    FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                  unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize);
    virtual ~FireSimulator() = default;
    void run();

private:
    FireSimulator(FireSimulator&&) = delete;
    FireSimulator(const FireSimulator&) = delete;
    FireSimulator& operator=(FireSimulator&) = delete;

    std::vector <std::thread> m_firefighters;
    std::vector <std::thread> m_arsonists;

    volatile unsigned m_hatchets;
    volatile unsigned m_firehoses;
    volatile unsigned m_helmets;
    volatile unsigned m_initialFireSize;
};
