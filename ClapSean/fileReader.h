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

#ifndef CLAPSEAN_FILEREADER_H
#define CLAPSEAN_FILEREADER_H


class fileReader {
public:
    static std::unique_ptr<std::vector<string>> readFile(const string& filename);
    static void writeFile(const std::unique_ptr<std::vector<string>>& v, const string& filenameOut);
};


#endif //CLAPSEAN_FILEREADER_H
