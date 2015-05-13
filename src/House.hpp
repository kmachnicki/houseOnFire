#pragma once

#include <thread>
#include <mutex>

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
    bool m_isSomeoneInside;
    mutable std::mutex m_guard;
};
