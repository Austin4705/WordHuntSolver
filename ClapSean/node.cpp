//
// Created by wu_pe on 11/23/2021.
//

#include "node.h"

#include <memory>

//generste graph
std::array<node, 16> node::generateGraph(const string& s){
    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 5; j++){
            int nodeNumber = i*j-1;
        }
    }
    std::array<node, 16>  x;
    return x;
}

//recursively calculate permutations, recrusive function
static std::unique_ptr<std::vector<string>> node::permutations(const string& prev, node* thisN, int n, std::array<node, 16> graph){
    auto r = std::make_unique<std::vector<string>>();

    if(n == 1){
        r->push_back(prev+thisN->letter);
        return (r);
    }


    //for each eligible x node
    for(int i = 0; i < thisN->neighborNodes.size(); i++){
        if(thisN->neighborNodes[i] != nullptr){
            if(!thisN->neighborNodes[i]->isTraveled){
                thisN->neighborNodes[i]->isTraveled = true;
                auto nodeReturnVal = permutations(prev + thisN->letter, thisN->neighborNodes[i], n - 1, graph);
            }
        }
    }
    //vector<string> * s = permutations(c.substr(0, c.size-1));

    return r;
}

//get all the permutations and add it to the list
std::unique_ptr<std::vector<string>> node::totalPermutations(const string& c){
    //generate initial graph
    std::array<node, 16> graph = generateGraph(c);

    auto returnVal = std::make_unique<std::vector<string>>();
    //for each starting node
    for(int i = 0; i < 16; i++)
        //for each letter length
        for(int j = 1; j <= 16; j++){
            //copy array to a new one
            std::array<node, 16> newGraph;
            std::copy(graph.begin(), graph.end(), newGraph.begin());

            //find all the permutations with that starting node nad length
            std::unique_ptr<std::vector<string>> temp = permutations(c, j, newGraph);
            //copy values into return array
            returnVal->insert(
                    returnVal->end(),
                    make_move_iterator(temp->begin()),
                    make_move_iterator(temp->end())
            );
        }
    return returnVal;
}




//convert algebraic values to actual values (makes time complexity  o(n)



//    //search through all the words
//    auto * ok = new std::vector<string>;
//    auto ref = trieTree;
//    for(auto &x : *p){
//        for(int i = 0; i < x.size(); i++){
//            int charindex = x[i] - 'a';
//            //if at the end and good, push back
//            if(i == x.size()-1 && ref->indexedW){
//                ok->push_back(x);
//            }
//            //if null then the tree ends and break otherwise set the next pointer
//            if((*ref->x)[charindex] == nullptr){
//                break;
//            }
//            else{
//                ref = (*ref->x)[charindex];
//            }
//
//        }
//    }
//
//    std::cout << "\n";
//    for(auto &x : *ok){
//        std::cout << x << "\n";
//    }