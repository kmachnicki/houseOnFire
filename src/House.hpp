#pragma once

#include <thread>
#include <mutex>

#include "OutputWindow.hpp"

class House
{
public:
    House(unsigned initialFireSize, OutputWindow* screen);
    virtual ~House() = default;

    unsigned getFireSize() const;
    bool isSomeoneInside() const;
    void extinguish();
    void ignite();

private:
    volatile unsigned m_fireSize;
    std::shared_ptr<OutputWindow> m_screen;
    mutable std::mutex m_guard;
};
