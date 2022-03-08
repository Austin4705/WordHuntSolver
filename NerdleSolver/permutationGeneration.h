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

namespace permutationGeneration {
    //takes generates valid subset of permutations with a check function and
    template <class T, int len>
    constexpr std::vector<std::array<T, len>>
    totalPermutation(const std::vector<T> & inputPerm, const std::function<bool(std::array<T, len> &)> & f){
//        std::function<std::vector<std::array<T, len>>(const std::vector<T> &)> z = generateAllPermutations<T, len>();
        auto z = generateAllPermutations<T, len>(inputPerm);
        return validPermutations<T, len>(z, f);
    }

    //takes a list of permutations and a check function, returns the ones that are good
    template <class T, int len>
    constexpr std::vector<std::array<T, len>>
    validPermutations(const std::vector<std::array<T, len>> & inputPerm, const std::function<bool(std::array<T, len> &)> &f);

    //generates all permutations
    template <class T, int len>
    constexpr std::vector<std::array<T, len>>
    generateAllPermutations(const std::vector<T> & inputPerm);
};


#endif //NERDLESOLVER_PERMUTATIONGENERATION_H
