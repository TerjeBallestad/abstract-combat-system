#include <memory>
#include "Character.h"
#include "Util.h"

Character::Character() {
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

float Character::TakeSpellDamage(Spell *spell) {
    auto pt = personalityType;

    //float blackDamage   = (spell->black * (pt->black * 0.50)) + (spell->black * (pt->blue * 1.00)) + (spell->black * (pt->red * 1.00)) + (spell->black * (pt->green * 1.50)) + (spell->black * (pt->white * 1.50));

    BTVector lbdrg;

    lbdrg.l = CalculateDamage(
        spell->damage.l, pt->basePersonality * BTVector(0.5, 1.0, 1.5, 1.5, 1.0)
    );
    lbdrg.b = CalculateDamage(
        spell->damage.b, pt->basePersonality * BTVector(1.0, 0.5, 1.0, 1.5, 1.5)
    );
    lbdrg.d = CalculateDamage(
        spell->damage.d, pt->basePersonality * BTVector(1.5, 1.0, 0.5, 1.0, 1.5)
    );
    lbdrg.r = CalculateDamage(
        spell->damage.r, pt->basePersonality * BTVector(1.5, 1.5, 1.0, 0.5, 1.0)
    );
    lbdrg.g = CalculateDamage(
        spell->damage.g, pt->basePersonality * BTVector(1.0, 1.5, 1.5, 1.0, 0.5)
    );

    auto scores = GetEnergy();
    
    lbdrg += scores;

    float damage = lbdrg.Sum();

    health -= damage;

    return damage;
}