#pragma once

#include "Util.h"

enum BaseType { 
    light, 
    dark, 
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
        return light;
    } else if (c == "D") {
        return dark;
    } else if (c == "B") {
        return blue;
    } else if (c == "A") {
        return all;
    }

    return none;
}

inline string BaseTypeToTerminalColor(BaseType color, std::string txt) {
    if (color == light) {
        return RGB(txt, 210, 210, 100);
    } else if (color == dark) {
        return RGB(txt, 100, 50, 100);
    } else if (color == blue) {
        return RGB(txt, 50, 50, 210);
    } else if (color == red) {
        return RGB(txt, 210, 50, 50);
    } else if (color == green) {
        return RGB(txt, 50, 210, 50);
    } else if (color == all) {
        return RGB(txt, 255, 255, 255);
    }else if (color == none) {
        return RGB(txt, 25, 25, 25);
    }

     return string("\u001b[37m");
}