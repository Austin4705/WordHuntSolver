//
// Created by wu_pe on 3/2/2022.
//

#include "expressionEvaluation.h"

template <class T, int len>
constexpr bool expressionEvaluation::checkStrNumExp(std::array<T, len>& eval){
    typedef std::array<T, len> arrT;
    //find the equal sign and split string, could use std::find but custom seems to be faster
    //guaranteed that a and b both have no = sign, just values and operators
    arrT a, b;
    bool pastEquals = false;
    for(auto &x : eval){
        if(x == '='){
            if(pastEquals) return false;
            else pastEquals = true;
            continue;
        }
        pastEquals ? a.push_back(x) : b.push_back(x);
    }
    if(!pastEquals) return false;
    //calculate each side of exp
    int intA = 0, intB = 0;
    for(auto &x : std::vector<std::pair<string, int>>{{a, intA}, {b, intB}}){

    }
    //if they equal eachother, return true
    return intA == intB;
}