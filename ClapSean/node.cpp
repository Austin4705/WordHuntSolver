//
// Created by wu_pe on 11/23/2021.
//

#include "node.h"


//generste graph
std::array<node *, 16> node::generateGraph(const string& s){
    assert(s.size() == 16);
    std::array<node*, 16>  returnVal{nullptr};
    node* arrN[4][4]{};
    int nodeNum = 1;
    //declare and init all the nodes
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            auto workingNode = new node(s[nodeNum-1], nodeNum);
            returnVal[nodeNum-1] = workingNode;
            arrN[i][j] = workingNode;
            nodeNum++;
        }
    }
    //fill in the interconnected array of nodes
    //indicie adj going around from 1-8, https://cdn.discordapp.com/attachments/192058549776416768/913136317100068914/unknown.png
    const std::array<std::pair<int, int>, 8> indiciesAdj = {{ {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1} }};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            auto workingNode = arrN[i][j];
            for(int n = 0; n < 8; n++){
                int i1 = i+indiciesAdj[n].first, j1 = j+indiciesAdj[n].second;
                //if in valid range set the node to the right one in the graph
                if(i1 < 3 && i1 >= 0 && j1 < 3 && j1 >= 0){
                    workingNode->neighborNodes[n] = arrN[i1][j1];
                }
            }
        }
    }
    return returnVal;
}

//recursively calculate permutations, recrusive function, super inneficent and bad implementation, should be fine tho
void node::permutations(const std::shared_ptr<std::vector<string>>& returnVal, const string& prev, node* thisN, std::array<bool, 16> graph){
    returnVal->push_back(prev);
    //for each eligible x node
    auto neigNodes = thisN->neighborNodes;
    for(int i = 0; i < neigNodes.size(); i++){
        if(neigNodes[i] != nullptr){
            if(!graph[neigNodes[i]->id]){
                graph[neigNodes[i]->id] = true;
                //ok did change it to be much better, still recursive and not dynamic programming but idc
                permutations(returnVal, prev + thisN->letter, neigNodes[i], graph);
            }
        }
    }
}

//get all the permutations and add it to the list
std::shared_ptr<std::vector<string>> node::totalPermutations(const string& c){
    std::cout << "Generating Graph\n";
    auto t11 = std::chrono::high_resolution_clock::now();
    //generate initial graph
    std::array<node*, 16> graph = generateGraph(c);

    auto t21 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff1 = t21-t11;
    std::cout << "Graph Finished Building in: " << diff1.count() << " ms\n";
    std::cout << "Generating Permutations\n";
    auto t12 = std::chrono::high_resolution_clock::now();

    auto returnVal = std::make_shared<std::vector<string>>();
    //for each starting node
    for(int i = 0; i < 16; i++)
        //find all the permutations with that starting node nad length
        permutations(returnVal, c, graph[i], std::array<bool, 16>()={false});

    auto t22 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff2 = t22-t12;
    std::cout << "All Permutations Finished Building in: " << diff2.count() << " ms\n";

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