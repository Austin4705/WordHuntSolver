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
    template <class T, int len>
    constexpr std::vector<std::array<T, len>>
    totalPermutation(const std::vector<T> & inputPerm, const std::function<bool(std::array<T, len> &)> & f){
        std::function<std::vector<std::array<T, len>>(const std::vector<T> &)> z = generateAllPermutations<T, len>;
        return validPermutations<T, len>(z, f);
    }

    template <class T, int len>
    constexpr std::vector<std::array<T, len>>
    validPermutations(const std::vector<std::array<T, len>> & inputPerm, const std::function<bool(std::array<T, len> &)> &f);

    template <class T, int len>
    constexpr std::vector<std::array<T, len>>
    generateAllPermutations(const std::vector<T> & inputPerm);

};


#endif //NERDLESOLVER_PERMUTATIONGENERATION_H
