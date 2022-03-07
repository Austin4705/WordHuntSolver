//
// Created by wu_pe on 11/8/2021.
//

#include "permutation.h"


std::unique_ptr<std::vector<string>> permutation::search(const std::shared_ptr<std::vector<string>>& p, const std::shared_ptr<trie>& trieTree){
    //search through all the words
    auto validValues = std::make_unique<std::vector<string>>();
    //for each string in p
    for(auto &x : *p){
        auto ref = trieTree;
        //for each character
        for(int i = 0; i < x.size(); i++){
            int charIndex = x[i] - 'a';
            //if at the end and good, push back
            if(i == x.size()-1 && ref->indexedW){
                validValues->push_back(x);
            }
            //if null then the tree ends and break otherwise set the next pointer
            if((ref->x)[charIndex] == nullptr){
                break;
            }
            else{
                ref = (ref->x)[charIndex];
            }
        }
    }
    return validValues;
}
