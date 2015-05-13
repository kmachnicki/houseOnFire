#include <iostream>

#include "FireSimulator.hpp"

int main(int argc, char* argv[])
{
    if (argc != 7)
    {
        std::cerr << "Incorrect nubmer of parameters. Usage: [firefighters] [arsonists] [hatchets] [firehoses] [helmets] [initial_house_hp]" << std::endl;
        return 1;
    }

    unsigned numOfFirefighters = stoul(std::string(argv[1]));
    unsigned numOfArsonists    = stoul(std::string(argv[2]));
    unsigned numOfHatchets     = stoul(std::string(argv[3]));
    unsigned numOfFirehoses    = stoul(std::string(argv[4]));
    unsigned numOfHelmets      = stoul(std::string(argv[5]));
    unsigned initialFireSize   = stoul(std::string(argv[6]));

    FireSimulator simulator(numOfFirefighters, numOfArsonists, numOfHatchets, numOfFirehoses, numOfHelmets, initialFireSize);
    simulator.run();

    return 0;
}
