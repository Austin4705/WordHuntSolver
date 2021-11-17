cmake_minimum_required(VERSION 3.17)
project(ClapSean)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClapSean main.cpp permutation.cpp permutation.h fileReader.cpp fileReader.h trie.cpp trie.h)