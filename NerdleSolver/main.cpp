#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <functional>
#include <utility>
using std::string;

template <class T, int len>
constexpr std::vector<std::array<T, len>> * permutations(const std::vector<T> & inputPerm){
    typedef std::array<T, len> arrT;
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
        if(at.sz == len-2){//code is repeated, but this saves one exponentaion of stuff on on the stack instead of inputting later
            for(auto &x : inputPerm)
                permRetArr->push_back(arrayContainer(at, x).a);
        }
        else{
            for(auto &x : inputPerm)
                stack->template emplace(arrayContainer(at.a, x));
        }
    }
    return permRetArr;
}

//given a check function and a list of vectors, return the vectors that work
template <class T, int len>
constexpr std::vector<std::array<T, len>> validPermutations(std::vector<std::array<T, len>> inputPerm, const std::function<bool(const std::array<T, len>&)> & f){
    std::vector<T> retVec;
    std::for_each(inputPerm.begin(), inputPerm.end(),[&retVec, &f](T chk){
        if(f(chk)) retVec.push_back();
    });
    return retVec;
}

template <class T, int len>
constexpr bool checkStrNumExp(const std::array<T, len>& eval){
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


int main() {
    //hopefully this happens at compile time;
    const std::vector<char> num = {'0', '1', '2', '3', '4', '5', '6','7','8', '9', '+', '-', '*', '/', '='};
    //{"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "+", "-", "*", "/", "="};
    const int len = 8;
    const auto p = permutations<char, len>(num);
    const auto goodPermutations = validPermutations<std::array<string, len>>(p, checkStrNumExp<std::array<>);
    //calculate the entropy of each one :)


    //stuff for runtime:



    return 0;
}
