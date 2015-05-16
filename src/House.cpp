#include "House.hpp"

House::House(unsigned initialFireSize, std::shared_ptr<OutputWindow> screen)
    : m_fireSize(initialFireSize)
    , m_screen(screen)
{
    m_screen->refreshHouse(m_fireSize);
}

unsigned House::getFireSize() const
{
    return m_fireSize;
}

void House::extinguish()
{
    std::unique_lock<std::mutex> lock(m_lock, std::defer_lock);
    if (lock.try_lock())
    {
        std::this_thread::sleep_for(std::chrono::seconds(6));
        --m_fireSize;
        m_screen->refreshHouse(m_fireSize);
    }
}

void House::ignite()
{
    std::unique_lock<std::mutex> lock(m_lock, std::defer_lock);
    if (lock.try_lock())
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        ++m_fireSize;
        m_screen->refreshHouse(m_fireSize);
    }
}
