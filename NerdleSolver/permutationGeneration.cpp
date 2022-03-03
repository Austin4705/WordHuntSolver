//
// Created by wu_pe on 3/2/2022.
//

#include "permutationGeneration.h"



template <class T, int len>
static constexpr permutationGeneration::std::vector<arrT> * generateAllPermutations(const std::vector<T> & inputPerm){
    struct arrayContainer{
        arrT a{};
        int sz = 0;
        arrayContainer() = default;
        arrayContainer(arrayContainer prev, T x) : sz(prev.sz+1), a(prev.a) { a.at(sz) = x; }
        explicit arrayContainer(T x){ a.at(sz) = x; }
        explicit operator arrT() const { return a; }
    };
    auto stack = new std::stack<arrayContainer>; //better not stack overflow :), (stack based recursion)
    std::for_each(inputPerm.begin(), inputPerm.end(), [&stack](const T& x){
        stack->template emplace(x);
    });
    //auto permRetArr = new std::vector<arrT>(); //return permutation array
    auto permRetArr = new std::vector<arrT>;
    while(!stack->empty()){
        arrayContainer at = stack->top(); stack->pop();
        //code is repeated, but this saves one exponentaion of stuff on on the stack instead of inputting later
        if(at.sz == len-2) for(auto &x : inputPerm)
                permRetArr->push_back(arrayContainer(at, x).a);
        else for(auto &x : inputPerm)
                stack->emplace(arrayContainer(at, x));
    }
    return permRetArr;
}

//given a check function and a list of vectors, return the vectors that work
template <class T, int len>
static constexpr permutationGeneration::std::vector<arrT> validPermutations(std::vector<arrT> inputPerm, const std::function<bool(const std::array<T, len>&)> & f){
    std::vector<T> retVec;
    std::for_each(inputPerm.begin(), inputPerm.end(),[&retVec, &f](T chk){
        if(f(chk)) retVec.push_back();
    });
    return retVec;
}
