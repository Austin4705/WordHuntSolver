//
// Created by wu_pe on 11/16/2021.
//
#include <array>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#include <iostream>
using std::string;
#include "profiler.h"

#ifndef CLAPSEAN_TRIE_H
#define CLAPSEAN_TRIE_H


//nothing sus here :)
class trie {
public:
    static std::shared_ptr<trie> makeTrie(const std::vector<std::string> & v);

    //trie value, word indexed bool, char character stored(unessecary but im lazy), 26 for the other ones
    std::array<std::shared_ptr<trie>, 26> x = {nullptr};
    char c = ' ';
    bool indexedW = false;
    trie() = default;
    explicit trie(char cc) {
        c = cc;
    }


};

#endif //CLAPSEAN_TRIE_H
