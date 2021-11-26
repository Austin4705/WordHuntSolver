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
                int i1 = i+indiciesAdj[n].second, j1 = j+indiciesAdj[n].first;
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
void node::permutations(const std::shared_ptr<std::vector<string>>& returnVal, const string& prev, node* thisN, std::array<bool, 16> graph, std::shared_ptr<trie> t){
    returnVal->push_back(prev);

    graph[thisN->id-1] = true;//mark visited
    //save computation
    //if seq is in trie only then continue
    bool inTrieB = inTrie(t, prev);
    if(!inTrieB)
        return;

    //for each eligible x node
    auto neigNodes = thisN->neighborNodes;
    for(int i = 0; i < neigNodes.size(); i++){
        if(neigNodes[i] != nullptr){//if a node
            if(!graph[neigNodes[i]->id-1]){//if now visited
                //ok did change it to be much better, still recursive and not dynamic programming but idc

                    //call next version, iterate until all neighboring nodes have been traveled or no possible combinations
                    permutations(returnVal, prev + neigNodes[i]->letter, neigNodes[i], graph, t);
            }
        }
    }
}

//get all the permutations and add it to the list
std::shared_ptr<std::vector<string>> node::totalPermutations(const string& c, const std::shared_ptr<trie>& t){
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
    for(int i = 0; i < 16; i++) {
        //find all the permutations with that starting node nad length
        permutations(returnVal, string(1, c[i]), graph[i], std::array<bool, 16>() = {false}, t);
    }
    auto t22 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff2 = t22-t12;
    std::cout << "All Permutations Finished Building in: " << diff2.count() << " ms\n";

    return returnVal;
}

bool node::inTrie(std::shared_ptr<trie> t, const string& s){
    auto rc = t;
    for(int i = 0; i < s.size(); i++){
        int sval = s[i] - 'a';
        if(rc->x[sval] != nullptr){
            rc = rc->x[sval];
        }
        else{
            return false;
        }
    }
    return true;
}


//convert algebraic values to actual values (makes time complexity  o(n)


