#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <functional>
#include <utility>
#include "permutationGeneration.h"
#include "expressionEvaluation.h"
using std::string;



int main() {
    //hopefully this happens at compile time;
    const std::vector<char> num = {'0', '1', '2', '3', '4', '5', '6','7','8', '9', '+', '-', '*', '/', '='};
    const int len = 8;
    auto y = expressionEvaluation::checkStrNumExp<char, 8>;
    const auto x = permutationGeneration::totalPermutation<char, 8>(num, y);
    //calculate the entropy of each one :)
    //stuff for runtime:
    return 0;
}
