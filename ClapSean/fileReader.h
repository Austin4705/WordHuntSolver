//
// Created by wu_pe on 11/16/2021.
//
#include <string>
#include <vector>
#include <memory>
using std::string;

#ifndef CLAPSEAN_FILEREADER_H
#define CLAPSEAN_FILEREADER_H


class fileReader {
public:
    static std::unique_ptr<std::vector<string>> readFile(const string& filename);
};


#endif //CLAPSEAN_FILEREADER_H
