#include "Person.hpp"

Person::Person(unsigned id, std::shared_ptr<Playground> playground,
               std::shared_ptr<House> house, std::shared_ptr<OutputWindow> screen)
    : m_id(id)
    , m_status("Waiting")
    , m_isRunning(true)
    , m_playground(playground)
    , m_house(house)
    , m_screen(screen)
{}

void Person::kill()
{
    m_isRunning.store(false);
}

unsigned Person::getId() const
{
    return m_id;
}

void Person::updateStatus(const std::string& newStatus)
{
    m_status = newStatus;
}

std::string Person::getStatus() const
{
    return m_status;
}
