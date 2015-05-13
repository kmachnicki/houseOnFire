#include "Firefighter.hpp"

Firefighter::Firefighter()
{}

Firefighter::~Firefighter()
{}

void Firefighter::run()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
