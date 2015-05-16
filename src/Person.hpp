#pragma once

#include <string>
#include <memory>
#include <atomic>

#include "Playground.hpp"
#include "House.hpp"
#include "OutputWindow.hpp"

class Person
{
public:
    explicit Person(unsigned id, std::shared_ptr<Playground> playground,
                    std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen);
    virtual ~Person() = default;

    virtual void run() = 0;

    void kill();
    unsigned getId() const;
    std::string getStatus() const;

protected:
    unsigned m_id;
    std::string m_status;
    std::atomic<bool> m_isRunning;
    std::shared_ptr<Playground> m_playground;
    std::shared_ptr<House> m_house;
    std::shared_ptr<OutputWindow> m_screen;
};
