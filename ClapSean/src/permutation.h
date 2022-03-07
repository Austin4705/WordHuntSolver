//
// Created by wu_pe on 11/8/2021.
//
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <cmath>
#include <cassert>
#include <iostream>
#include <chrono>
#include "trie.h"
using std::string;

#ifndef CLAPSEAN_PERMUTATION_H
#define CLAPSEAN_PERMUTATION_H


class permutation {
    public:
    static std::unique_ptr<std::vector<string>> search(const std::shared_ptr<std::vector<string>>& p, const std::shared_ptr<trie>& trieTree);
    };


#endif //CLAPSEAN_PERMUTATION_H
