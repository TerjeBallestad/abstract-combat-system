#include <iostream>
#include <ctime>
#include "acs-character.h"
#include "acs-damage.h"

enum BaseType { white, black, blue, red, green };

struct PuzzlePiece {
    int ID;
    BaseType north, south, east, west;
};

struct Card {
    int damage;
    float castTime;
    float cooldown;
    PuzzlePiece puzzlePiece;
};

class Deck {
    Card cards [50];
};

class Hand {
    Card cards [10];
};

int main () 
{
    srand(time(0));



    Character *player = new Character();
    
    player->personalityType->black = 0.2;
    player->personalityType->white = 0.2;
    player->personalityType->blue = 0.2;
    player->personalityType->green = 0.2;
    player->personalityType->red = 0.2;

    player->personalityType->intellect = 0.5;
    player->personalityType->creativity = 0.5;
    player->personalityType->wisdom = 0.5;

    player->spells[0] = new GenericBlackSpell();
    player->spells[1] = new GenericGreenSpell();
    player->spells[2] = new GenericBlueSpell();



    Character *A = new Character();
    
    A->personalityType->black = 0;
    A->personalityType->white = 1;
    A->personalityType->blue = 0;
    A->personalityType->green = 0;
    A->personalityType->red = 0;

    A->personalityType->intellect = 0.5;
    A->personalityType->creativity = 0.5;
    A->personalityType->wisdom = 0.5;

    A->spells[0] = new GenericBlackSpell();
    A->spells[1] = new GenericWhiteSpell();
    A->spells[2] = new GenericGreenSpell();


    Character *B = new Character();
    
    B->personalityType->black = 0.5;
    B->personalityType->white = 0;
    B->personalityType->blue = 0.5;
    B->personalityType->green = 0;
    B->personalityType->red = 0;

    B->personalityType->intellect = 0.5;
    B->personalityType->creativity = 0.5;
    B->personalityType->wisdom = 0.5;


    B->spells[0] = new GenericBlueSpell();
    B->spells[1] = new GenericBlackSpell();
    B->spells[2] = new GenericRedSpell();


    Character *C = new Character();
    
    C->personalityType->black = 0.3333333333;
    C->personalityType->white = 0;
    C->personalityType->blue = 0;
    C->personalityType->green = 0.3333333333;
    C->personalityType->red = 0.3333333333;

    C->personalityType->intellect = 0.5;
    C->personalityType->creativity = 0.5;
    C->personalityType->wisdom = 0.5;

    C->spells[0] = new GenericBlackSpell();
    C->spells[1] = new GenericGreenSpell();
    C->spells[2] = new GenericBlueSpell();

    std::cout << "You find yourself in an open field.\n";
    std::cout << "There are 3 enemies in front of you.\n";
    std::cout << "Who do you attack?\n";

    Character *enemy;
    Spell *spell;

    int selected = 0;
    std::cin >> selected;

    if (selected == 1) {
        enemy = A;
    } else if (selected == 2) {
        enemy = B;
    } else if (selected == 3) {
        enemy = C;
    }

    while (true) {

        std::cout << "You have 3 spells.\n\tSpell 1: " << player->spells[0]->toString() << "\n\tSpell 2: " << player->spells[1]->toString() << "\n\tSpell 3: " << player->spells[2]->toString() << "\n";

        std::cin >> selected;
        
        if (selected == 1) {
            spell = player->spells[0];
        } else if (selected == 2) {
            spell = player->spells[1];
        } else if (selected == 3) {
            spell = player->spells[2];
        }

        float dmg;

        dmg = enemy->TakeSpellDamage(spell);
        std::cout << "You did " << dmg << " damage\n";
        std::cout << "Enemy now has " << enemy->health << " health\n";

        dmg = player->TakeSpellDamage(enemy->spells[rand()%3]);
        std::cout << "The enemy did " << dmg << " damage\n";
        std::cout << "You now have " << player->health << " health\n";

        if (!enemy->IsAlive()) {
            std::cout << "You won!";
            break;
        }

        if (!player->IsAlive()) {
            std::cout << "You died!";
            break;
        }

    }


    return 0;
}

/*

me: cast? fire, ice, light
enemy: 


*/