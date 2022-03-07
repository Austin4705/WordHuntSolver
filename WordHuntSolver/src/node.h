//
// Created by wu_pe on 11/23/2021.
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
#include "profiler.h"

#ifndef CLAPSEAN_NODE_H
#define CLAPSEAN_NODE_H

//wow!! a node; so cool
class node {
public:
    //constructors
    node() = default;
    explicit node(char _letter, int _id) {
       letter = _letter; id = _id;
    }

    //bool isTraveled = false;
    char letter = ' ';
    std::array<node*, 8> neighborNodes = {nullptr};
    int id = -1;


    static std::shared_ptr<std::vector<string>> totalPermutations(const string& c, const std::shared_ptr<trie>& t);
    static bool inTrie(std::shared_ptr<trie> t, const string& s);
    //helper functions
private:
    static std::array<node *, 16> generateGraph(const string& s);
    static void permutations(const std::shared_ptr<std::vector<string>>& returnVal, const string& prev, node* thisN, std::array<bool, 16> graph, std::shared_ptr<trie> t);
};


#endif //CLAPSEAN_NODE_H
