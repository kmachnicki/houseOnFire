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

void Playground::updateStatus()
{
    m_screen->refreshResources(m_hatchets, m_firehoses, m_helmets, m_matches, m_fuel);
}

bool Playground::acquireHatchet()
{
    std::unique_lock<std::mutex> lock(m_hatchetsLock, std::adopt_lock);
    if (m_hatchets > 0)
    {
        --m_hatchets;
        updateStatus();
        return true;
    }
    return false;
}

bool Playground::acquireFirehose()
{
    std::unique_lock<std::mutex> lock(m_firehosesLock, std::adopt_lock);
    if (m_firehoses > 0)
    {
        --m_firehoses;
        updateStatus();
        return true;
    }
    return false;
}

bool Playground::acquireHelmet()
{
    std::unique_lock<std::mutex> lock(m_helmetsLock, std::adopt_lock);
    if (m_helmets > 0)
    {
        --m_helmets;
        updateStatus();
        return true;
    }
    return false;
}

bool Playground::acquireMatch()
{
    std::unique_lock<std::mutex> lock(m_matchesLock, std::adopt_lock);
    if (m_matches > 0)
    {
        --m_matches;
        updateStatus();
        return true;
    }
    return false;
}

bool Playground::acquireFuel()
{
    std::unique_lock<std::mutex> lock(m_fuelLock, std::adopt_lock);
    if (m_fuel > 0)
    {
        --m_fuel;
        updateStatus();
        return true;
    }
    return false;
}

void Playground::storeHatchet()
{
    std::unique_lock<std::mutex> lock(m_hatchetsLock, std::adopt_lock);
    ++m_hatchets;
    updateStatus();
}

void Playground::storeFirehose()
{
    std::unique_lock<std::mutex> lock(m_firehosesLock, std::adopt_lock);
    ++m_firehoses;
    updateStatus();
}

void Playground::storeHelmet()
{
    std::unique_lock<std::mutex> lock(m_helmetsLock, std::adopt_lock);
    ++m_helmets;
    updateStatus();
}

void Playground::storeMatch()
{
    std::unique_lock<std::mutex> lock(m_matchesLock, std::adopt_lock);
    ++m_matches;
    updateStatus();
}

void Playground::storeFuel()
{
    std::unique_lock<std::mutex> lock(m_fuelLock, std::adopt_lock);
    ++m_fuel;
    updateStatus();
}
