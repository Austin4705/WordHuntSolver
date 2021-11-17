//
// Created by wu_pe on 11/16/2021.
//
#include <array>
#include <vector>
#include <string>
using std::string;

#ifndef CLAPSEAN_TRIE_H
#define CLAPSEAN_TRIE_H


//nothing sus here :)
class trie{
public:
    static trie * root;
    static char * makeTrie(const std::vector<string> & v);

    std::array<trie*, 26> * x = new std::array<trie*, 26>;
    char c = ' ';
    bool indexedW = false;
    trie()= default;
    explicit trie(char cc){
        c = cc;
    }



#endif //CLAPSEAN_TRIE_H
