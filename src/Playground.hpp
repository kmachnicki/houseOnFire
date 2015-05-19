#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>

#include "OutputWindow.hpp"

class Playground
{
public:
    Playground(unsigned numOfHatchets, unsigned numOfFirehoses, unsigned numOfHelmets,
               unsigned numOfMatches, unsigned numOfFuel, std::shared_ptr<OutputWindow> screen);

    bool acquireHatchet();
    bool acquireFirehose();
    bool acquireHelmet();
    bool acquireMatch();
    bool acquireFuel();

    void storeHatchet();
    void storeFirehose();
    void storeHelmet();
    void storeMatch();
    void storeFuel();

private:
    volatile unsigned m_hatchets;
    volatile unsigned m_firehoses;
    volatile unsigned m_helmets;
    volatile unsigned m_matches;
    volatile unsigned m_fuel;

    mutable std::mutex m_hatchetsLock;
    mutable std::mutex m_firehosesLock;
    mutable std::mutex m_helmetsLock;
    mutable std::mutex m_matchesLock;
    mutable std::mutex m_fuelLock;

    std::shared_ptr<OutputWindow> m_screen;

    void updateStatus();
};
