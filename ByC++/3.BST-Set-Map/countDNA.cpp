#include "map.hpp"
#include <map>
#include <iostream>
#include "helpers.hpp"

int main()
{
    const char * path=" data/genetic_data.txt"; //change according to your path 

    std::string dna = getFileFirstLine(path);

    map::Map<char, int> dnaCounter;

    for (char &c : dna)
    {

        dnaCounter.value(c)++;
    }

    dnaCounter.printAll();

    return 0;
}