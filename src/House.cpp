#include "House.hpp"

House::House(unsigned initialFireSize)
    : m_fireSize(initialFireSize)
    , m_isSomeoneInside(false)
{}

unsigned House::getFireSize() const
{
    return m_fireSize;
}

bool House::isSomeoneInside() const
{
    return m_isSomeoneInside;
}

void House::extinguish()
{
    m_isSomeoneInside = true;
    std::lock_guard<std::mutex> lock(m_guard);
    --m_fireSize;
    std::this_thread::sleep_for(std::chrono::seconds(6));
    m_isSomeoneInside = false;
}

void House::ignite()
{
    m_isSomeoneInside = true;
    std::lock_guard<std::mutex> lock(m_guard);
    ++m_fireSize;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    m_isSomeoneInside = false;
}
