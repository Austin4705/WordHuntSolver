//
// Created by wu_pe on 11/16/2021.
//

#include "fileReader.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <utility>

using std::string;

std::unique_ptr<std::vector<string>> fileReader::readFile(const string& filename) {
    std::filesystem::path p(std::filesystem::current_path()); p = p / ".." / filename;
    std::cout << "Init FileStream ... ";
    std::ifstream tin(p);
    std::cout << "Filestream Made, initializing copying data\n";
    auto t1 = std::chrono::high_resolution_clock::now();
    std::unique_ptr<std::vector<string>> v(new std::vector<string>());
    string s;
    while(std::getline(tin, s)){
        v->push_back(s);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff = t2-t1;
    std::cout << "Read Words: " << v->size() << " in " << diff.count() << " ms.\n";
    return v;
}