#include "Spell.h"

Spell::Spell(std::string name_, BTVector damage_, BTVector cost_) {
    damage = damage_;
    cost = cost_;
    name = name_;
}

std::string Spell::ToString() {
    return name;
}