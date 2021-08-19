#pragma once

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

    inline BTVector operator*(BTVector ldbrg) {
        return BTVector(
            l*ldbrg.l,
            d*ldbrg.d,
            b*ldbrg.b,
            r*ldbrg.r,
            g*ldbrg.g
        );
    }

    inline BTVector operator-(BTVector ldbrg) {
        return BTVector(
            l-ldbrg.l,
            d-ldbrg.d,
            b-ldbrg.b,
            r-ldbrg.r,
            g-ldbrg.g
        );
    }

    inline BTVector operator+=(BTVector ldbrg) {
        return BTVector(
            l+ldbrg.l,
            d+ldbrg.d,
            b+ldbrg.b,
            r+ldbrg.r,
            g+ldbrg.g
        );
    }


    inline bool IsAnyBelowZero() {
        return l<= 0.0 || d<= 0.0 || b <= 0.0 || r<=0.0 || g <= 0.0;
    }

    inline float Sum() {
        return l + b + d + r + g;
    }

    std::string ToString() {
        return std::string("scores:\n") +
            "l: " + std::to_string(l) + "\n" +
            "b: " + std::to_string(b) + "\n"
            "d: " + std::to_string(d) + "\n"
            "r: " + std::to_string(r) + "\n"
            "g: " + std::to_string(g) + "\n";
    }
};