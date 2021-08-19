#pragma once

class Character;
#include "Spell.h"

class Damage {
public: 
    Damage(Character *instigator, Spell *spell);
    Character *instigator;
    Spell *spell;
};