//
// Created by wu_pe on 3/2/2022.
//

#ifndef NERDLESOLVER_EXPRESSIONEVALUATION_H
#define NERDLESOLVER_EXPRESSIONEVALUATION_H

#include <vector>
#include <stack>
#include <algorithm>
#include <array>
#include <functional>
#include <utility>
#include <string>
using std::string;

namespace expressionEvaluation {
    template <class T, int len>
    constexpr bool checkStrNumExp(const std::array<T, len>& eval);
};


#endif //NERDLESOLVER_EXPRESSIONEVALUATION_H
