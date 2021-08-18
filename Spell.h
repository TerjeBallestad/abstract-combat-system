#pragma once

#include <string>
#include "BTVector.hpp"

class Spell {
public:
    BTVector damage = BTVector(0,0,0,0,0);
    BTVector cost = BTVector(0,0,0,0,0);
    Spell(std::string name, BTVector damage, BTVector cost);

    std::string name = "unknown spell";
    std::string ToString();
};
