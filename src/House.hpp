#pragma once

#include <thread>
#include <mutex>

#include "OutputWindow.hpp"

class House
{
public:
    House(unsigned initialFireSize);
    virtual ~House() = default;

    unsigned getFireSize() const;
    bool isSomeoneInside() const;
    void extinguish();
    void ignite();

private:
    volatile unsigned m_fireSize;
    mutable std::mutex m_guard;
};
