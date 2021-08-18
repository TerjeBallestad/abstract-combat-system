#include "Spell.h"

Spell::Spell(std::string name_, BTVector type_) {
    spellType = type_;
    name = name_;
}

std::string Spell::ToString() {
    return name;
}