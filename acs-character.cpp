#include <memory>
#include "acs-character.h"
#include "util.h"

Character::Character() {
    personalityType = (PersonalityType *)malloc(sizeof(PersonalityType));

    personalityType->white = Random();
    personalityType->black = Random();
    personalityType->blue = Random();
    personalityType->red = Random();
    personalityType->green = Random();

    personalityType->intellect = Random();
    personalityType->wisdom = Random();
    personalityType->creativity = Random();
}

float CalculateDamage(float color, float a, float b, float c, float d, float e) {
    return
        (color * a) +
        (color * b) + 
        (color * c) + 
        (color * d) + 
        (color * e); 
}

float Character::TakeSpellDamage(Spell *spell) {
    auto pt = personalityType;

    //float blackDamage   = (spell->black * (pt->black * 0.50)) + (spell->black * (pt->blue * 1.00)) + (spell->black * (pt->red * 1.00)) + (spell->black * (pt->green * 1.50)) + (spell->black * (pt->white * 1.50));

    float whiteDamage = CalculateDamage(
        spell->white, 
        pt->white * 0.5,
        pt->blue * 1.0,
        pt->black * 1.5,
        pt->red * 1.5,
        pt->green * 1.0
    );
    float blueDamage = CalculateDamage(
        spell->blue, 
        pt->white * 1.0,
        pt->blue * 0.5,
        pt->black * 1.0,
        pt->red * 1.5,
        pt->green * 1.5
    );
    float blackDamage = CalculateDamage(
        spell->black, 
        pt->white * 1.50,
        pt->blue * 1.00,
        pt->black * 0.50,
        pt->red * 1.00,
        pt->green * 1.50
    );

    float redDamage = CalculateDamage(
        spell->red, 
        pt->white * 1.5,
        pt->blue * 1.5,
        pt->black * 1.0,
        pt->red * 0.5,
        pt->green * 1.0
    );
    float greenDamage = CalculateDamage(
        spell->green, 
        pt->white * 1.0,
        pt->blue * 1.5,
        pt->black * 1.5,
        pt->red * 1.0,
        pt->green * 0.5
    );
    
    float damage = whiteDamage + blueDamage + blackDamage + redDamage + greenDamage;

    
    // float blueDamage    = (spell->blue  * (pt->black * 1.00)) + (spell->blue  * (pt->blue * 0.50)) + (spell->blue  * (pt->red * 1.50)) + (spell->blue  * (pt->green * 1.50)) + (spell->blue  * (pt->white * 1.00));
    // float redDamage     = (spell->red   * (pt->black * 1.00)) + (spell->red   * (pt->blue * 1.50)) + (spell->red   * (pt->red * 0.50)) + (spell->red   * (pt->green * 1.00)) + (spell->red   * (pt->white * 1.50));
    // float greenDamage   = (spell->green * (pt->black * 1.50)) + (spell->green * (pt->blue * 1.50)) + (spell->green * (pt->red * 1.00)) + (spell->green * (pt->green * 0.50)) + (spell->green * (pt->white * 1.00));
    // float whiteDamage   = (spell->white * (pt->black * 1.50)) + (spell->white * (pt->blue * 1.00)) + (spell->white * (pt->red * 1.50)) + (spell->white * (pt->green * 1.00)) + (spell->white * (pt->white * 0.50));


/*
    auto dmg = new SpellDamage();
    dmg->black = (spell->white + spell->green) / 2.0;´
    dmg->red = (spell->white + spell->blue) / 2.0;
    dmg->green = (spell->blue + spell->black) / 2.0;
    dmg->white = (spell->black + spell->red) / 2.0;
    dmg->blue = (spell->red + spell->green) / 2.0;
    */

   health -= damage;

    return damage;
}