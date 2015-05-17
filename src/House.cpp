#include "House.hpp"
#include "Firefighter.hpp"
#include "Arsonist.hpp"

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

bool House::extinguish(Firefighter* firefighter)
{
    std::unique_lock<std::timed_mutex> lock(m_lock, std::defer_lock);
    if (lock.try_lock_for(std::chrono::milliseconds(1000)))
    {
        firefighter->updateStatus("Extinguishing!");
        std::this_thread::sleep_for(std::chrono::seconds(6));
        --m_fireSize;
        m_screen->refreshHouse(m_fireSize);
        return true;
    }
    else
    {
        firefighter->updateStatus("No luck");
        return false;
    }
}

bool House::ignite(Arsonist* arsonist)
{
    std::unique_lock<std::timed_mutex> lock(m_lock, std::defer_lock);
    if (lock.try_lock_for(std::chrono::milliseconds(1000)))
    {
        arsonist->updateStatus("Igniting!");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        ++m_fireSize;
        m_screen->refreshHouse(m_fireSize);
        return true;
    }
    else
    {
        arsonist->updateStatus("No luck");
        return false;
    }
}
