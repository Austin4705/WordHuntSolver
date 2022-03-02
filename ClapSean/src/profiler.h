//
// Created by wu_pe on 2/7/2022.
//
#include <iostream>
#include <sstream>
#include <chrono>
using std::string;

#ifndef CLAPSEAN_PROFILER_H
#define CLAPSEAN_PROFILER_H



class profiler {
private:
    std::chrono::steady_clock::time_point begin;
    bool verbose;
    std::stringstream logfile;
public:
    profiler();
    void start();
    void toc();
    void toc(const std::string& s);
    void stop();
    void stop(const std::string& s);
    string dump();
};







#endif //CLAPSEAN_PROFILER_H
