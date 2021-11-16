#include "bits/stdc++.h"
using namespace std;

//penis penis penis
class trie{
public:
    array<trie*, 26> * x = new array<trie*, 26>;
    char * c = nullptr;
    bool indexedW = false;
    trie()= default;
    explicit trie(char cc){
        *c = cc;
    }
};

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
}

//recursively calculate permutations, recrusive function
vector<string> * permutations(string c, int n, array<node, 16> graph){
    //vector<string> * s = permutations(c.substr(0, c.size-1));
    return s;
}

vector<string> * totalPermutations(string c){
    //generate initial graph
    array<node, 16> graph = generateGraph(s);

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


}

4





int main() {
    //importing words
    ifstream tin(R"(C:\Dev\USACO\Practice\General\ClapSean\words.txt)");
    vector<string> v;
    string s;
    while(getline(tin, s))
        v.push_back(s);

//    auto vs = new array<vector<string>, 25>;
//    for(auto &x : v){
//        int size = x.size()-1;
//        vs->at(size).push_back(x);
//    }
//    cout << v[0];

    //make a trie
    auto * trieBase = new trie(' ');
    for(auto &x : v){
        trie * ref = trieBase;
        //for each letter
        for(int i = 0; i < x.size(); i++){
            int charindex = x[i] - 'a';
            array<trie*, 26> * xTemp = ref->x;
            //if not a trie then make one
            if( (*xTemp)[charindex] == nullptr ){
                trie * trieTemp = new trie(x[i]);
                (*xTemp)[charindex] = trieTemp;
            }
            //set the letter (could be more efficent with index of arr, idgaf
            *(*xTemp)[charindex]->c = (x[i]);
            //if end of word
            if(i = x.size()-1){
                ref->indexedW = true;
            }
            //set the next pointer for the next letter
            ref = (*ref->x)[charindex];
        }
    }

    //generate all algbraic values of a graph structure
    //generate permutations
    //auto * p = permutations(userI);
    auto * p = new vector<string>;
    p->push_back(userI);


    //intake letters
    string userI; cin >> userI;
    assert(userI.length() == 16);

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