//
// Created by wu_pe on 11/16/2021.
//
#include "trie.h"

std::shared_ptr<trie> trie::makeTrie(const std::vector<std::string> & v){
    std::cout << "Staring Trie Building from Vector\n";
    auto t1 = std::chrono::high_resolution_clock::now();

    //make a trie
    std::shared_ptr<trie> trieBase(new trie(' '));
    //for every work in vector
    for(auto &x : v){
        auto ref = trieBase;//reset referecne for the word
        //for each letter in each word
        for(int i = 0; i < x.size(); i++){
            //letter from 0-25
            int charindex = x[i] - 'a';
            //find the arr ptr from the current node
            //std::array<trie*, 26> * xTemp = ref->x;
            //if not a trie then make one
            if( (ref->x)[charindex] == nullptr ){
                std::shared_ptr<trie> trieTemp(new trie(x[i]));
                (ref->x)[charindex] = trieTemp;
            }
            //set the next pointer for the next letter
            ref = std::shared_ptr<trie>((ref->x)[charindex]);
            //if end of word
            if(i == x.size()-1){
                ref->indexedW = true;
            }
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff = t2-t1;
    std::cout << "Trie Finished Building in: " << diff.count() << " ms\n";
    //return the tree
    return trieBase;
}