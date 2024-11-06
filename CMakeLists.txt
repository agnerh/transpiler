cmake_minimum_required(VERSION 3.15)

project(TsTranspiler VERSION 0.1
                  DESCRIPTION "Transpiles TS files into JS"
                  LANGUAGES CXX)

add_executable(transpiler main.cpp)