#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <functional>
#include <utility>
#include "permutationGeneration.cpp"
using std::string;


template <class T, int len>
constexpr std::vector<std::array<T, len>>
tP(const std::vector<T> & inputPerm, const std::function<bool(std::array<T, len> &)> f){
    return std::vector<std::array<T, len>>();
}



int main() {
    //hopefully this happens at compile time;
    const std::vector<char> num = {'0', '1', '2', '3', '4', '5', '6','7','8', '9', '+', '-', '*', '/', '='};
    const int len = 8;
    //auto y =  expressionEvaluation::checkStrNumExp<char, len>;
//    const auto x = tP<char, len>(num, y);
    //const auto xx = permutationGeneration::totalPermutation<char, len>(num, expressionEvaluation::checkStrNumExp<char, len>);
    const std::vector<std::array<char, len>> z = permutationGeneration::generateAllPermutations<char, len>(num);
//    for(auto &x : z){
//        for(auto &y : x){
//            std::cout << y;
//        }
//        std::cout << "\n";
//    }

    //const auto x = permutationGeneration::totalPermutation<char, 8>(num, y);
    //calculate the entropy of each one :)
    //stuff for runtime:
    return 0;
}
