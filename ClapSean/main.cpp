#include <array>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <cassert>
#include "trie.h"
#include "fileReader.h"
#include "node.h"

using std::string;


int main() {
    //importing words
    string filename = R"(words.txt)";
    auto v = fileReader::readFile(filename);
    std::cout << "\nData intake complete. Generating Trie Structure\n";

    //convert array into trie
    auto trieTree = trie::makeTrie(*v);

    //intake letters from uer input
    string userI; std::cin >> userI;
    assert(userI.length() == 16);

    //generate all algbraic values of a graph structure
    //generate permutations and input into graph
    auto p = node::totalPermutations(userI);

//    auto * p = new std::vector<string>;
//    p->push_back(userI);



    return 0;
}
