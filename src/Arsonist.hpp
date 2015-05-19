#pragma once

#include <sstream>
#include <thread>
#include <mutex>
#include <memory>

#include "Playground.hpp"
#include "House.hpp"
#include "Person.hpp"

class Arsonist final : public Person
{
public:
    explicit Arsonist(unsigned id, std::shared_ptr<Playground> playground,
                      std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen);
    ~Arsonist() = default;
    void run() override final;
    void updateStatus(const std::string& newStatus);
};
