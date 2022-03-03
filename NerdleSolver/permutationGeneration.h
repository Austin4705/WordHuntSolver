//
// Created by wu_pe on 3/2/2022.
//

#ifndef NERDLESOLVER_PERMUTATIONGENERATION_H
#define NERDLESOLVER_PERMUTATIONGENERATION_H
#include <vector>
#include <stack>
#include <algorithm>
#include <array>
#include <functional>
#include <utility>

class permutationGeneration {
    typedef std::array<T, len> arrT;
    static constexpr permutationGeneration::std::vector<arrT> validPermutations(std::vector<arrT> inputPerm, const std::function<bool(const arrT&)> & f);
    static constexpr permutationGeneration::std::vector<arrT> * generateAllPermutations(const std::vector<T> & inputPerm);

public:
    static constexpr std::vector<arrT> totalPermutation(const std::vector<T> & inputPerm, const std::function<bool(const arrT&)> & f){
        auto x = generateAllPermutations(inputPerm);
        auto y =
    }

};


#endif //NERDLESOLVER_PERMUTATIONGENERATION_H
