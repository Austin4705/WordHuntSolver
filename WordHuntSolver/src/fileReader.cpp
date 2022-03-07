//
// Created by wu_pe on 11/16/2021.
//
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <stdio.h>
#include <utility>
using std::string;
#include "fileReader.h"

//template <typename name>
std::unique_ptr<std::vector<string>> fileReader::readFile(const string& filename) {
    std::filesystem::path p(std::filesystem::current_path()); p = p / ".." / filename;
    std::cout << "Init FileStream ... ";
    std::ifstream tin(p);
    std::cout << "Filestream Made, initializing copying data\n";
    std::unique_ptr<std::vector<string>> v(new std::vector<string>());
    profiler P = profiler(); P.start();
    string s;
    while(std::getline(tin, s)){
        //make lowercase
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        v->push_back(s);
    }
    P.stop(); P.dump();
    return v;
}

void fileReader::writeFile(const std::unique_ptr<std::vector<string>> &v, const string &filenameOut) {
    std::ofstream outfile(filenameOut);
    for(auto &x : *v){
        outfile << x << "\n";
    }
    outfile.close();
}
