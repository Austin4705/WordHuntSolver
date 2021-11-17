#include "bits/stdc++.h"
#include "fileReader.h"
#include "trie.h"
using namespace std;


//your mother
class node{
public:
    bool isTraveled = false;
    char letter = ' ';
    array<node*, 8> neighborNodes = {nullptr};
};

//generste graph
array<node, 16> generateGraph(string s){
    for(int i = 1; i < 5; i++){
        for(int j = 1; j < 5; j++){
            int nodeNumber = i*j-1;
        }
    }
    array<node, 16>  x;
    return x;
}

//recursively calculate permutations, recrusive function
vector<string> * permutations(string c, int n, array<node, 16> graph){
    //vector<string> * s = permutations(c.substr(0, c.size-1));
    return (new vector<string>);
}

vector<string> * totalPermutations(string c){
    //generate initial graph
    array<node, 16> graph = generateGraph(c);

    auto * returnVal = new vector<string>;
    //for each starting node
    for(int i = 0; i < 16; i++)
        //for each letter length
        for(int j = 1; j < 17; j++){
            //get all the permutations and add it to the list
            array<node, 16> newGraph;
            copy(graph.begin(), graph.end(), newGraph.begin());

            vector<string> * temp = permutations(c, j, newGraph);
            returnVal->insert(
                    returnVal->end(),
                    make_move_iterator(temp->begin()),
                    make_move_iterator(temp->end())
            );
        }

    return (new vector<string>);

}






int main() {
    //importing words
    string filename = R"(words.txt)";
    auto v = fileReader::readFile(filename);
    std::cout << "\nData intake complete. Generating Trie Structure\n";





    //intake letters
    string userI; cin >> userI;
    assert(userI.length() == 16);

    //generate all algbraic values of a graph structure
    //generate permutations
    //auto * p = permutations(userI);
    auto * p = new vector<string>;
    p->push_back(userI);


    //convert algebraic values to actual values (makes time complexity  o(n)



    //search through all the words
    vector<string> * ok = new vector<string>;
    trie * ref = trieBase;
    for(auto &x : *p){
        for(int i = 0; i < x.size(); i++){
            int charindex = x[i] - 'a';
            //if at the end and good, push back
            if(i == x.size()-1 && ref->indexedW){
                ok->push_back(x);
            }
            //if null then the tree ends and break otherwise set the next pointer
            if((*ref->x)[charindex] == nullptr){
                break;
            }
            else{
                ref = (*ref->x)[charindex];
            }

        }
    }

    cout << "\n";
    for(auto &x : *ok){
        cout << x << "\n";
    }

    return 0;
}
