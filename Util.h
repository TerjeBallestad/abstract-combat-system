#pragma once

#include <stdlib.h> 
#include <cstdlib> 
#include <string>
#include "acs.h"

using std::string;

inline float Random() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

inline string RGB(std::string text, int r, int g, int b) {
    return string("\033[38;2;")+std::to_string(r)+";"+std::to_string(g)+";"+std::to_string(b)+"m"+text+"\033[0;00m";
}

inline std::string Grey(std::string str) {
    return RGB(str, 75, 75, 75);
}