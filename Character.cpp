#include <memory>
#include "Character.h"
#include "Util.h"

Character::Character() {
    personalityType = (PersonalityType *)malloc(sizeof(PersonalityType));

    personalityType->lbdrg = LBDRG(Random(), Random(), Random(), Random(), Random());

    personalityType->intellect = Random();
    personalityType->wisdom = Random();
    personalityType->creativity = Random();

    #define x new Talent(" ", 0, none, none, none, none, true)
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

LBDRG Character::GetEnergy() {
    return grid->GetEnergy();
}

float CalculateDamage(float color, LBDRG lbdrg) {
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

    LBDRG lbdrg;

    lbdrg.l = CalculateDamage(
        spell->lbdrg.l, pt->lbdrg * LBDRG(0.5, 1.0, 1.5, 1.5, 1.0)
    );
    lbdrg.b = CalculateDamage(
        spell->lbdrg.b, pt->lbdrg * LBDRG(1.0, 0.5, 1.0, 1.5, 1.5)
    );
    lbdrg.d = CalculateDamage(
        spell->lbdrg.d, pt->lbdrg * LBDRG(1.50, 1.00, 0.50, 1.00, 1.50)
    );
    lbdrg.r = CalculateDamage(
        spell->lbdrg.r, pt->lbdrg * LBDRG(1.5, 1.5, 1.0, 0.5, 1.0)
    );
    lbdrg.g = CalculateDamage(
        spell->lbdrg.g, pt->lbdrg * LBDRG(1.0, 1.5, 1.5, 1.0, 0.5)
    );

    auto scores = GetEnergy();
    
    lbdrg += scores;

    float damage = lbdrg.Sum();

    health -= damage;

    return damage;
}