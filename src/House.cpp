#include "House.hpp"

House::House(unsigned initialFireSize, OutputWindow* screen)
    : m_fireSize(initialFireSize)
    , m_screen(screen)
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
    m_screen->refreshHouse(m_fireSize);
}

void House::ignite()
{
    std::lock_guard<std::mutex> lock(m_guard);
    ++m_fireSize;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m_screen->refreshHouse(m_fireSize);
}
