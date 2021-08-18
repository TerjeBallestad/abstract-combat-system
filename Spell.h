#pragma once
#include <string>
#include "LBDRG.hpp"
class Spell {
public:
    LBDRG lbdrg = LBDRG(0,0,0,0,0);
    virtual const char *ToString() {
        return "base spell";
    }
};

class GenericBlackSpell: public Spell {
public:
    const char *ToString() {
        return "generic dark spell";
    }
    GenericBlackSpell(): Spell() {
        lbdrg.d = 10;
    }
};


class GenericWhiteSpell: public Spell {
public:
    const char *ToString() {
        return "generic white spell";
    }
    GenericWhiteSpell(): Spell() {
        lbdrg.l = 3;
    }
};


class GenericGreenSpell: public Spell {
public:
    const char *ToString() {
        return "generic green spell";
    }
    GenericGreenSpell(): Spell() {
        lbdrg.g = 8;
    }
};


class GenericBlueSpell: public Spell {
public:
    const char *ToString() {
        return "generic blue spell";
    }
    GenericBlueSpell(): Spell() {
        lbdrg.b = 5;
    }
};


class GenericRedSpell: public Spell {
public:
    const char *ToString() {
        return "generic red spell";
    }
    GenericRedSpell(): Spell() {
        lbdrg.r = 1;
    }
};