#include <string>

class Spell {
public:
    float white; 
    float black; 
    float blue; 
    float red; 
    float green;

    Spell() {
        white = 0;
        black = 0;
        blue = 0;
        red = 0;
        green = 0;
    }

    virtual const char *toString() {
        return "base spell";
    }
};

class GenericBlackSpell: public Spell {
public:
    const char *toString() {
        return "generic black spell";
    }
    GenericBlackSpell(): Spell() {
        black = 10;
    }
};


class GenericWhiteSpell: public Spell {
public:
    const char *toString() {
        return "generic white spell";
    }
    GenericWhiteSpell(): Spell() {
        white = 3;
    }
};


class GenericGreenSpell: public Spell {
public:
    const char *toString() {
        return "generic green spell";
    }
    GenericGreenSpell(): Spell() {
        green = 8;
    }
};


class GenericBlueSpell: public Spell {
public:
    const char *toString() {
        return "generic blue spell";
    }
    GenericBlueSpell(): Spell() {
        blue = 5;
    }
};


class GenericRedSpell: public Spell {
public:
    const char *toString() {
        return "generic red spell";
    }
    GenericRedSpell(): Spell() {
        red = 1;
    }
};