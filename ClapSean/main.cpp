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
#include "permutation.h"

#include <gtest/gtest.h>
//lol u thought i would use these thingys
//#include "bits/stdc++.h"
//using namespace std;

using std::string;

//BETA G WHAT ARE YOU DOING
int main() {
    //importing words
    string filename = R"(lotawords.txt)";
    auto v = fileReader::readFile(filename);

    std::cout << "Data intake complete. Generating Trie Structure\n";

    //convert array into trie
    auto trieTree = trie::makeTrie(*v);

    //intake letters from uer input
    std::cout << "Please input string: \n----------------\n";
    string userI = "uplsdedaealniiww";
    //string userI; std::cin >> userI;
    assert(userI.length() == 16);
    std::cout << "User input complete, generating all possible permutations of user input in game\n";

    //generate all algbraic values of a graph structure
    //generate permutations and input into graph
    auto x = node::totalPermutations(userI, trieTree);
    auto xx = permutation::search(x, trieTree);
    std::sort(xx->begin(),xx->end(),
    [](string& s1, string& s2){
            if(s1.size() == s2.size())
                return s1 < s2;
            return ( s1.size() < s2.size() );
        }
    );
    //output this monstrosity 😩 what have I created 😩😩😩😩😩😩😩
    fileReader::writeFile(xx, "newFileOutputWowSoCool-1.0.txt");
    for(const auto& y : *xx){
        std::cout << y << "\n";
    }

    //the chance of this abomination actually returnning 0 is like nothing
    //😃😃😃😃😃😃😃
    //😊😊😊😊😊😊😊
    return 0;
}
