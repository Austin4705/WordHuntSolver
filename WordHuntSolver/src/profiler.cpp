//
// Created by wu_pe on 2/7/2022.
//

#include "profiler.h"



profiler::profiler() {
    verbose = true;
    this->start();
}

void profiler::start() {
    begin = std::chrono::steady_clock::now();
}

void profiler::stop(const string& s) {
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << s << " Time elapsed = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1e6 << std::endl;
    logfile << s << "," << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1e6 << std::endl;
}

void profiler::stop() {
    this->stop("");
}

void profiler::toc() {
    this->toc("");
}

void profiler::toc(const string& s) {
    this->stop(s);
    this->start();
}

string profiler::dump() {
    return logfile.str();
}
