#pragma once

#include "Spell.h"
#include "Damage.h"
#include "TalentGrid.h"
#include "LBDRG.hpp"

struct PersonalityType {
    LBDRG lbdrg;
    float creativity;
    float intellect;
    float wisdom;
};

class Character {
    public:
        Character();

        float health = 100;

        float TakeSpellDamage(Spell *spell);
        LBDRG GetEnergy();

        Spell *spells[3];
        TalentGrid *grid;

        PersonalityType* personalityType;

        bool IsAlive() {
            return health > 0;
        }
};