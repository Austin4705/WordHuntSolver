cmake_minimum_required(VERSION 3.17)
project(NerdleSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(NerdleSolver main.cpp permutationGeneration.cpp permutationGeneration.h expressionEvaluation.cpp expressionEvaluation.h)