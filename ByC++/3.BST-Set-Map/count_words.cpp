#include "map.hpp"
//#include <map>
#include <iostream>
#include "helpers.hpp"

int main()
{
     const char *path = "data/carl_sagan.txt"; //change according to your path

    std::vector<std::string> words = getFileWords(path);

    map::Map<std::string, int> wordMap;

    for (std::string &word : words)
    {
        wordMap.value(word)++;
    }

    wordMap.printAll();

    return 0;
}