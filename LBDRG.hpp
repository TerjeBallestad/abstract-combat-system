#pragma once

class LBDRG {
public:
    float l = 0;
    float b = 0;
    float d = 0;
    float r = 0;
    float g = 0;

    inline LBDRG(){
        
    };

    inline LBDRG(float l_, float b_, float d_, float r_, float g_) {
        l = l_;
        b = b_;
        d = d_;
        r = r_;
        g = g_;
    }

    inline LBDRG operator*(LBDRG ldbrg) {
        return LBDRG(
            l*ldbrg.l,
            d*ldbrg.d,
            b*ldbrg.b,
            r*ldbrg.r,
            g*ldbrg.g
        );
    }

      inline LBDRG operator+=(LBDRG ldbrg) {
        return LBDRG(
            l+ldbrg.l,
            d+ldbrg.d,
            b+ldbrg.b,
            r+ldbrg.r,
            g+ldbrg.g
        );
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