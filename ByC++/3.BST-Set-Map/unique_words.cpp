#include "set.hpp"
#include "helpers.hpp"

int main()
{
    const char *path = "data/carl_sagan.txt"; //change according to your path
    std::vector<std::string> words = getFileWords(path);
    std::cout << words.size() << std::endl;

    set::Set<std::string> wordSet;

    for (std::string &word : words)
        wordSet.add(word);

    std::cout << wordSet.size() << std::endl;
    wordSet.printAll();

    return 0;
}