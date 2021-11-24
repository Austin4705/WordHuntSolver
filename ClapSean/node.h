//
// Created by wu_pe on 11/23/2021.
//

#include <vector>
#include <string>
#include <array>
#include <memory>
#include "math.h"
#include "assert.h"
using std::string;


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


    static std::shared_ptr<std::vector<string>> totalPermutations(const string& c);
    //helper functions
private:
    static std::array<node *, 16> generateGraph(const string& s);
    static void permutations(const std::shared_ptr<std::vector<string>>& returnVal, const string& prev, node* thisN, int n, std::array<bool, 16> graph);
};


#endif //CLAPSEAN_NODE_H
