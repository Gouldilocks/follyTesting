cmake_minimum_required(VERSION 3.17)
project(follyTesting)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG -Ofast)
configure_file(words_one_hundred words_one_hundred)
configure_file(words_long words_long)
add_executable(follyTesting main.cpp rudimentaryVector.h)
