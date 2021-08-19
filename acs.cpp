#include <iostream>
#include <vector>
#include <string>
#include "Character.h"
#include "Data.h"

int main () 
{
    std::vector<Character *> characters;

    Character *PC = new Character("PlayerCharacter");

    characters.push_back(PC);

    std::vector<Talent *> talents = LoadTalents();
    std::vector<Talent *> slots = LoadSlots(); 
    std::vector<Spell *> spells = LoadSpells();
    LoadToGrid(talents, slots, PC->talentGrid);
    LoadSpellsToCharacter(spells, PC);  
   
    std::cout << PC->talentGrid->ToString();
    std::cout << PC->GetEnergy().ToString();

    std::vector<Character *> enemies;

    enemies.push_back(new Character("A"));
    enemies.push_back(new Character("B"));
    enemies.push_back(new Character("C"));


    for (auto enemy : enemies) {
        LoadSpellsToCharacter(spells, enemy);
        LoadToGrid(talents, slots, enemy->talentGrid);

        characters.push_back(enemy);
    }
    
    std::cout << "You find yourself in an open field.\n";
    std::cout << "There are "<<enemies.size()<<" enemies in front of you.\n";
    for (int i = 0; i < enemies.size(); i++) {
        std::cout << enemies[i]->name;
        if (i == enemies.size() - 2) {
            std::cout << " and ";
        } else if (i != enemies.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << ". Who do you attack?\n";

    Character *enemy = nullptr;
    Spell *spell;

    std::string selected;    

    while (!enemy) {
        std::cin >> selected;
        for (auto chr : enemies) {
            if (chr->name == selected) {
                enemy = chr;
                break;
            }
        }
        if (!enemy) {
            std::cout << "Could not find enemy "<<selected<<" try again.\n";
        }
    }


    while (true) {

        std::cout << "You have 3 spells.\n\tSpell 1: " << PC->spells[0]->ToString() << "\n\tSpell 2: " << PC->spells[1]->ToString() << "\n\tSpell 3: " << PC->spells[2]->ToString() << "\n";

        int selectedSpell;
        std::cin >> selectedSpell;

        {

            auto dmg = PC->CastSpell(PC->spells[selectedSpell%3]);
            if (dmg) {
                enemy->TakeDamage(dmg);
            }
        }

        {

            auto dmg = enemy->CastSpell(enemy->spells[rand()%3]);
            if (dmg) {
                PC->TakeDamage(dmg);
            }
        }

        if (!enemy->IsAlive()) {
            std::cout << "You won!";
            break;
        }

        if (!PC->IsAlive()) {
            std::cout << "You died!";
            break;
        }


        for (auto chr : characters) {
            chr->Update();
        }
    }


    return 0;
}

/*

me: cast? fire, ice, light
enemy: 


*/