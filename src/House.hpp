#pragma once

#include <chrono>
#include <thread>
#include <mutex>

#include "OutputWindow.hpp"

class Firefighter;
class Arsonist;

class House
{
public:
    House(unsigned initialFireSize, std::shared_ptr<OutputWindow> screen);
    virtual ~House() = default;

    unsigned getFireSize() const;
    bool isSomeoneInside() const;
    void extinguish(Firefighter* firefighter);
    void ignite(Arsonist* arsonist);

private:
    volatile unsigned m_fireSize;
    std::shared_ptr<OutputWindow> m_screen;
    mutable std::timed_mutex m_lock;
};
