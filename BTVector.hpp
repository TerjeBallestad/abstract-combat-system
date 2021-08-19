#pragma once

#include "acs.h"

class BTVector {
public:
    float l = 0;
    float b = 0;
    float d = 0;
    float r = 0;
    float g = 0;

    inline BTVector(){};

    inline BTVector(float l_, float b_, float d_, float r_, float g_) {
        l = l_;
        b = b_;
        d = d_;
        r = r_;
        g = g_;
    }

    inline BTVector operator*(BTVector vector) {
        return BTVector(
            l*vector.l,
            d*vector.d,
            b*vector.b,
            r*vector.r,
            g*vector.g
        );
    }

    inline BTVector operator-(BTVector vector) {
        return BTVector(
            l-vector.l,
            d-vector.d,
            b-vector.b,
            r-vector.r,
            g-vector.g
        );
    }

    inline BTVector operator+=(BTVector vector) {
        return BTVector(
            l+=vector.l,
            d+=vector.d,
            b+=vector.b,
            r+=vector.r,
            g+=vector.g
        );
    }


    inline bool IsAnyBelowZero() {
        return l<= 0.0 || d<= 0.0 || b <= 0.0 || r<=0.0 || g <= 0.0;
    }

    inline float Sum() {
        return l + b + d + r + g;
    }

    std::string ToString() {
        return std::string("\n") +
        BaseTypeToTerminalColor(BaseType::light, std::to_string(l)) + "\n" +
        BaseTypeToTerminalColor(BaseType::blue, std::to_string(b)) + "\n" +
        BaseTypeToTerminalColor(BaseType::dark, std::to_string(d)) + "\n" +
        BaseTypeToTerminalColor(BaseType::red, std::to_string(r)) + "\n" +
        BaseTypeToTerminalColor(BaseType::green, std::to_string(g)) + "\n";
    }
};