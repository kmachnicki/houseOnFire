#include "FireSimulator.hpp"

FireSimulator::FireSimulator(unsigned numOfFirefighters, unsigned numOfArsonists, unsigned numOfHatchets,
                             unsigned numOfFirehoses, unsigned numOfHelmets, unsigned initialFireSize)
    : m_firefighters(numOfFirefighters)
    , m_arsonists(numOfArsonists)
    , m_playground(std::make_shared<Playground>(numOfHatchets, numOfFirehoses, numOfHelmets))
    , m_screen(std::make_shared<OutputWindow>())
    , m_house(std::make_shared<House>(initialFireSize, m_screen))
{}

void FireSimulator::run()
{
    m_screen->refreshHouse(20);
    for (unsigned i = 0; i < m_firefighters.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m_screen->refreshHouse(20+i);
        std::shared_ptr<Firefighter> firefighter = std::make_shared<Firefighter>(i, m_playground, m_house, m_screen);
        m_firefighters[i] = std::make_tuple(firefighter, std::move(std::thread(&Firefighter::run, firefighter)));
        //m_firefighters[i] = std::move(std::thread(&Firefighter::run, new Firefighter(i, m_playground, m_house, m_screen)));
    }

    for (unsigned i = 0; i < m_arsonists.size(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m_screen->refreshHouse(30+i);
        std::shared_ptr<Arsonist> arsonist = std::make_shared<Arsonist>(i, m_playground, m_house, m_screen);
        m_arsonists[i] = std::make_tuple(arsonist, std::move(std::thread(&Arsonist::run, arsonist)));
        //m_arsonists[i] = std::move(std::thread(&Arsonist::run, new Arsonist(i, m_playground, m_house, m_screen)));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    for (auto& firefighter : m_firefighters)
    {
        std::get<0>(firefighter)->kill();
        std::get<1>(firefighter).join();
    }

    for (auto& arsonist : m_arsonists)
    {
        std::get<0>(arsonist)->kill();
        std::get<1>(arsonist).join();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    endwin();
}
