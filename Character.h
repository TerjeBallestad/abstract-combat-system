#pragma once

#include "Spell.h"
#include "Damage.h"

struct PersonalityType {
    float white; 
    float black; 
    float blue; 
    float red; 
    float green;

    float creativity;
    float intellect;
    float wisdom;
};

class Character {
    public:
        Character();

        float health = 100;

        float TakeSpellDamage(Spell *spell);

        Spell *spells[3];

        PersonalityType* personalityType;

        bool IsAlive() {
            return health > 0;
        }
};