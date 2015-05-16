#pragma once

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <memory>

#include "Playground.hpp"
#include "House.hpp"
#include "Person.hpp"

class Firefighter final : public Person
{
public:
    explicit Firefighter(unsigned id, std::shared_ptr<Playground> playground,
                         std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen);
    ~Firefighter() = default;
    void run() override final;
    void updateStatus(const std::string& newStatus);
};
