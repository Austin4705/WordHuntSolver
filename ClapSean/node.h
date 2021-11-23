//
// Created by wu_pe on 11/23/2021.
//

#include <vector>
#include <string>
#include <array>
#include <memory>
using std::string;


#ifndef CLAPSEAN_NODE_H
#define CLAPSEAN_NODE_H

//wow!! a node; so cool
class node {
public:
    bool isTraveled = false;
    char letter = ' ';
    std::array<node*, 8> neighborNodes = {nullptr};

    static std::array<node, 16> generateGraph(const string& s);
    static std::unique_ptr<std::vector<string>> totalPermutations(const string& c);
    static std::unique_ptr<std::vector<string>> permutations(const string& prev, node* thisN, int n, std::array<node, 16> graph);
};


#endif //CLAPSEAN_NODE_H
