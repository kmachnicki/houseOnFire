#include "House.hpp"

House::House(unsigned initialFireSize)
    : m_fireSize(initialFireSize)
{}

unsigned House::getFireSize() const
{
    return m_fireSize;
}

void House::extinguish()
{
    std::lock_guard<std::mutex> lock(m_guard);
    --m_fireSize;
    std::this_thread::sleep_for(std::chrono::seconds(6));
    Screen.refreshHouse(m_fireSize);
}

void House::ignite()
{
    std::lock_guard<std::mutex> lock(m_guard);
    ++m_fireSize;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Screen.refreshHouse(m_fireSize);
}
