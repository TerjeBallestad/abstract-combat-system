#pragma once

#include <string>
#include "BTVector.hpp"

class Spell {
public:
    BTVector spellType = BTVector(0,0,0,0,0);
    Spell(std::string name, BTVector type);

    std::string name = "unknown spell";
    std::string ToString();
};
