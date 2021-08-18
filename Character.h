#pragma once

#include "Spell.h"
#include "Damage.h"
#include "TalentGrid.h"
#include "BTVector.hpp"

struct PersonalityType {
    BTVector basePersonality;
    float creativity;
    float intellect;
    float wisdom;
};

class Character {
    public:
        Character();

        float health = 100;

        float TakeSpellDamage(Spell *spell);
        BTVector GetEnergy();

        Spell *spells[3];
        TalentGrid *grid;

        PersonalityType* personalityType;

        bool IsAlive() {
            return health > 0;
        }
};