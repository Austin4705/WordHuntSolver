#include <array>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "trie.h"
#include "fileReader.h"
#include "node.h"

using std::string;


int main() {
    string q = "oojmeffoie";
    std::cout << q.size() << "\n";



    //importing words
    string filename = R"(words.txt)";
    auto v = fileReader::readFile(filename);

    std::cout << "Data intake complete. Generating Trie Structure\n";

    //convert array into trie
    auto trieTree = trie::makeTrie(*v);

    //intake letters from uer input
    std::cout << "Please input string: \n----------------\n";
    string userI = "giojejfcmeflmgkl";
    //string userI; std::cin >> userI;
    assert(userI.length() == 16);
    std::cout << "User input complete, generating all possible permutations of user input in game\n";

    //generate all algbraic values of a graph structure
    //generate permutations and input into graph
    auto x = node::totalPermutations(userI, trieTree);
    //std::sort(x->begin(),x->end(), [](string s1, string s2){return s1.size() < s2.size();});
    for(const auto& y : *x){
        //std::cout << y << "\n";
    }



//    auto * p = new std::vector<string>;
//    p->push_back(userI);



    return 0;
}
