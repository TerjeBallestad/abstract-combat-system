#pragma once

#include "Util.h"

enum BaseType { 
    white, 
    black, 
    blue, 
    red, 
    green, 
    none, 
    all 
};

inline BaseType CharToBaseType(std::string c) {
    if (c == "R") {
        return red;
    } else if (c == "G") {
        return green;
    } else if (c == "L") {
        return white;
    } else if (c == "D") {
        return black;
    } else if (c == "B") {
        return blue;
    } else if (c == "A") {
        return all;
    }

    return none;
}

inline string BaseTypeToTerminalColor(BaseType color, std::string txt) {
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