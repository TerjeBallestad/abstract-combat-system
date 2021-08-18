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

inline string Enum2Color(BaseType color, std::string txt) {
    if (color == white) {
        return RGB(txt, 255, 255, 255);
    } else if (color == black) {
        return RGB(txt, 0, 0, 0);
    } else if (color == blue) {
        return RGB(txt, 0, 255, 0);
    } else if (color == red) {
        return RGB(txt, 255, 0, 0);
    } else if (color == green) {
        return RGB(txt, 0, 255, 0);
    } else if (color == all) {
        return RGB(txt, 255, 255, 255);
    }else if (color == none) {
        return RGB(txt, 25, 25, 25);
    }

     return string("\u001b[37m");
}