//
// Created by wu_pe on 11/16/2021.
//

#include "trie.h"
#include <string>

#include <vector>
#include <array>

static char * trie::makeTrie(const std::vector<std::string> & v){
    //make a trie
    auto * trieBase = new trie(' ');
    for(auto &x : v){
        trie * ref = trieBase;
        //for each letter
        for(int i = 0; i < x.size(); i++){
            int charindex = x[i] - 'a';
            std::array<trie*, 26> * xTemp = ref->x;
            //if not a trie then make one
            if( (*xTemp)[charindex] == nullptr ){
                trie * trieTemp = new trie(x[i]);
                (*xTemp)[charindex] = trieTemp;
            }
            //set the letter (could be more efficent with index of arr, idgaf
            *(*xTemp)[charindex]->c = (x[i]);
            //if end of word
            if(i == x.size()-1){
                ref->indexedW = true;
            }
            //set the next pointer for the next letter
            ref = (*ref->x)[charindex];
        }
    }
}