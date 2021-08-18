#pragma once

#include <stdlib.h> 
#include <cstdlib> 
#include <string>
#include "ACS.h"

using std::string;

inline float Random() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

inline string Enum2Color(BaseType color) {
    if (color == white) {
        return string("\u001b[37m");
    } else if (color == black) {
        return string("\u001b[30m");
    } else if (color == blue) {
        return string("\u001b[34m");
    } else if (color == red) {
        return string("\u001b[31m");
    } else if (color == green) {
        return string("\u001b[32m");
    }

     return string("\u001b[37m");
}