#include "Arsonist.hpp"

Arsonist::Arsonist()
{}

Arsonist::~Arsonist()
{}

void Arsonist::run()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

std::string getCurrentStatus()
{
    return "y";
}
