#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <sstream>
#include <mutex>
#include <atomic>
#include <cassert>
#include <queue>
#include <memory>
#include <tuple>
#include <condition_variable>

#include "Arsonist.hpp"
#include "Firefighter.hpp"
#include "Playground.hpp"
#include "House.hpp"

class FireSimulator
{
public:
    FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                  unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize);
    virtual ~FireSimulator() = default;
    void run();

private:
    FireSimulator(FireSimulator&&) = delete;
    FireSimulator(const FireSimulator&) = delete;
    FireSimulator& operator=(FireSimulator&) = delete;

    std::vector<std::tuple<std::shared_ptr<Firefighter>, std::thread>> m_firefighters;
    std::vector<std::tuple<std::shared_ptr<Arsonist>, std::thread>> m_arsonists;

    std::shared_ptr<Playground> m_playground;
    std::shared_ptr<OutputWindow> m_screen;
    std::shared_ptr<House> m_house;
};
