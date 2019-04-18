#include "map.hpp"
#include <map>
#include <iostream>
#include "helpers.hpp"


int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::vector< std::string > words = getFileWords( argv[1] );
        
        map::Map< std::string, int > wordMap;

        for( std::string &word : words )
        {
            wordMap.value(word)++;
        }

        wordMap.printAll();
        
    }

    return 0;
}