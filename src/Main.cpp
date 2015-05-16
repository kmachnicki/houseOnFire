#include <iostream>

#include "FireSimulator.hpp"

int main(int argc, char* argv[])
{
    if (argc != 9)
    {
        std::cerr << "Incorrect nubmer of parameters. Usage: [firefighters] [arsonists] [hatchets] "
                     "[firehoses] [helmets] [matches] [fuel] [initial_house_hp]" << std::endl;
        return 1;
    }

    unsigned numOfFirefighters = stoul(std::string(argv[1]));
    unsigned numOfArsonists    = stoul(std::string(argv[2]));
    unsigned numOfHatchets     = stoul(std::string(argv[3]));
    unsigned numOfFirehoses    = stoul(std::string(argv[4]));
    unsigned numOfHelmets      = stoul(std::string(argv[5]));
    unsigned numOfMatches      = stoul(std::string(argv[6]));
    unsigned numOfFuel         = stoul(std::string(argv[7]));
    unsigned initialFireSize   = stoul(std::string(argv[8]));

    FireSimulator simulator(numOfFirefighters, numOfArsonists, numOfHatchets, numOfFirehoses,
                            numOfHelmets, numOfMatches, numOfFuel, initialFireSize);
    simulator.run();

    return 0;
}
