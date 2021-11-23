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
    std::unique_ptr<std::vector<string>> v(new std::vector<string>());
    string s;
    while(std::getline(tin, s)){
        v->push_back(s);
    }
    std::cout << "Read Words: " << v->size();
    return v;
}