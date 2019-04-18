#include "map.hpp"
#include <map>
#include <iostream>
#include "helpers.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string dna = getFileFirstLine(argv[1]);

        map::Map<char, int> dnaCounter;
        
        for ( char &c : dna )
        {
            
            dnaCounter.value(c)++;
        }

        dnaCounter.printAll();

    }

    return 0;
}