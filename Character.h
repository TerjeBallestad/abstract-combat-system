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
        Character(string name);
        string name;
        float health = 100;
        BTVector energy = * new BTVector(10,10,10,10,10);
        void Update();

        Damage *CastSpell(Spell *spell);
        void TakeDamage(Damage *spell);
        BTVector GetEnergy();

        Spell *spells[3];
        TalentGrid *talentGrid;

        PersonalityType* personalityType;

        bool IsAlive() {
            return health > 0;
        }
};