#include <iostream>
#include <vector>
#include <string>
#include "Character.h"
#include "Data.h"

int main () 
{
    Character *PC = new Character();

    std::vector<Talent *> talents = LoadTalents();
    std::vector<Talent *> slots = LoadSlots(); 
    std::vector<Spell *> spells = LoadSpells();
    LoadToGrid(talents, slots, PC->grid);
    LoadSpellsToCharacter(spells, PC);  
   
    std::cout << PC->grid->ToString();
    std::cout << PC->GetEnergy().ToString();

    Character *A = new Character();
    Character *B = new Character();
    Character *C = new Character();

    LoadSpellsToCharacter(spells, A);
    LoadSpellsToCharacter(spells, B);
    LoadSpellsToCharacter(spells, C);

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

        std::cout << "You have 3 spells.\n\tSpell 1: " << PC->spells[0]->ToString() << "\n\tSpell 2: " << PC->spells[1]->ToString() << "\n\tSpell 3: " << PC->spells[2]->ToString() << "\n";

        std::cin >> selected;
        
        if (selected == 1) {
            spell = PC->spells[0];
        } else if (selected == 2) {
            spell = PC->spells[1];
        } else if (selected == 3) {
            spell = PC->spells[2];
        }

        float dmg;

        dmg = enemy->TakeSpellDamage(spell);
        std::cout << "You did " << dmg << " damage\n";
        std::cout << "Enemy now has " << enemy->health << " health\n";

        dmg = PC->TakeSpellDamage(enemy->spells[rand()%3]);
        std::cout << "The enemy did " << dmg << " damage\n";
        std::cout << "You now have " << PC->health << " health\n";

        if (!enemy->IsAlive()) {
            std::cout << "You won!";
            break;
        }

        if (!PC->IsAlive()) {
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