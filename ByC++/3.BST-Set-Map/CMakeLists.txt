cmake_minimum_required(VERSION 3.13)
project(sbe201_bst_set_map_AbdallahDrwesh)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sbe201_bst_set_map_AbdallahDrwesh
        bst.hpp
        count_words.cpp
        countDNA.cpp
        helpers.hpp
        map.hpp
        set.hpp
        test_tree.cpp
        unique_words.cpp)
