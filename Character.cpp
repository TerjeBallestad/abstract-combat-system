#include <iostream>
#include <memory>
#include "Character.h"
#include "Util.h"
#include <algorithm>

Character::Character(std::string name_) {

    name = name_;

    personalityType = new PersonalityType();

    personalityType->basePersonality = BTVector(Random(), Random(), Random(), Random(), Random());

    personalityType->intellect = Random();
    personalityType->wisdom = Random();
    personalityType->creativity = Random();

    #define x new Talent(" ", none, none, none, none)
    grid = new TalentGrid();
    grid->slotGrid = {
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
    };
    #undef x

    #define x nullptr

    grid->talentGrid = {
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
        {x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
    };
}

BTVector Character::GetEnergy() {
    return grid->GetEnergy();
}

float CalculateDamage(float color, BTVector lbdrg) {
    return
        (color * lbdrg.l) +
        (color * lbdrg.b) + 
        (color * lbdrg.d) + 
        (color * lbdrg.r) + 
        (color * lbdrg.g); 
}

void Character::TakeDamage(Damage *dmg) {
    auto spell = dmg->spell;
    auto pt = personalityType;

    //float blackDamage   = (spell->black * (pt->black * 0.50)) + (spell->black * (pt->blue * 1.00)) + (spell->black * (pt->red * 1.00)) + (spell->black * (pt->green * 1.50)) + (spell->black * (pt->white * 1.50));

    BTVector damage;

    damage.l = CalculateDamage(
        spell->spellType.l, pt->basePersonality * BTVector(0.5, 1.0, 1.5, 1.5, 1.0)
    );
    damage.b = CalculateDamage(
        spell->spellType.b, pt->basePersonality * BTVector(1.0, 0.5, 1.0, 1.5, 1.5)
    );
    damage.d = CalculateDamage(
        spell->spellType.d, pt->basePersonality * BTVector(1.5, 1.0, 0.5, 1.0, 1.5)
    );
    damage.r = CalculateDamage(
        spell->spellType.r, pt->basePersonality * BTVector(1.5, 1.5, 1.0, 0.5, 1.0)
    );
    damage.g = CalculateDamage(
        spell->spellType.g, pt->basePersonality * BTVector(1.0, 1.5, 1.5, 1.0, 0.5)
    );

    float totalDamage = damage.Sum();

    health -= totalDamage;

    std::cout << dmg->instigator->name << " hit " << name << " with " << dmg->spell->name << " for " << totalDamage << "\n"; 
}

Damage *Character::CastSpell(Spell *spell) {
    auto dmg = new Damage(this, spell);

    auto newEnergy = energy - spell->spellType;

    if (newEnergy.IsAnyBelowZero()) {
        std::cout << name << " is out of energy\n";    
        return nullptr;
    }

    energy = newEnergy;

    std::cout << name << " cast " << dmg->spell->name << " for energy " << spell->spellType.ToString() << "\n"; 

    return dmg;
}

void Character::Update() {
    energy += grid->GetEnergy();

    energy.l = std::clamp(energy.l, (float)0, (float)100);
    energy.b = std::clamp(energy.b, (float)0, (float)100);
    energy.d = std::clamp(energy.d, (float)0, (float)100);
    energy.r = std::clamp(energy.r, (float)0, (float)100);
    energy.g = std::clamp(energy.g, (float)0, (float)100);

    std::cout << name << " now has " << energy.ToString() << " energy\n"; 
}