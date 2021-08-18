#include <iostream>
#include <vector>
#include <string>
#include "rapidcsv.h"
#include "Character.h"

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (trim(token));
    }

    res.push_back (trim(s.substr (pos_start)));
    return res;
}

BaseType parseColor(std::string c) {
    if (c == "R") {
        return red;
    } else if (c == "G") {
        return green;
    } else if (c == "L") {
        return white;
    } else if (c == "D") {
        return black;
    } else if (c == "B") {
        return blue;
    } else if (c == "A") {
        return all;
    }

    return none;
}

int main () 
{
    std::vector<Talent *> talents;
    std::vector<Talent *> slots;
    Character *ply = new Character();

    {
        rapidcsv::Document doc("./Talent Grid-Talents.csv", rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(';'));
        
        auto Id = doc.GetColumn<int>("Id");
        auto Name = doc.GetColumn<std::string>("Name");
        auto Energy = doc.GetColumn<float>("Energy");
        auto North = doc.GetColumn<std::string>("North");
        auto East = doc.GetColumn<std::string>("East");
        auto South = doc.GetColumn<std::string>("South");
        auto West = doc.GetColumn<std::string>("West");

        for (auto row : Id) {
            auto i = row;
            talents.push_back(
                new Talent(
                    Name[i], 
                    Energy[i], 
                    parseColor(North[i]), 
                    parseColor(East[i]), 
                    parseColor(South[i]), 
                    parseColor(West[i]),
                    false
                )
            );
        }
    }


    {
        rapidcsv::Document doc("./Talent Grid-Slots.csv", rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(';'));
        
        auto Id = doc.GetColumn<int>("Id");
        auto Name = doc.GetColumn<std::string>("Name");
        auto North = doc.GetColumn<std::string>("North");
        auto East = doc.GetColumn<std::string>("East");
        auto South = doc.GetColumn<std::string>("South");
        auto West = doc.GetColumn<std::string>("West");

        for (auto row : Id) {
            auto i = row;
            slots.push_back(
                new Talent(
                    Name[i], 
                    0, 
                    parseColor(North[i]), 
                    parseColor(East[i]), 
                    parseColor(South[i]), 
                    parseColor(West[i]),
                    true
                )
            );
        }
    }

    {
        rapidcsv::Document doc("./Talent Grid-Grid.csv", rapidcsv::LabelParams(0, 0), rapidcsv::SeparatorParams(';'));
        auto gridSize = doc.GetColumnCount();

        for (int x = 0; x < gridSize; x++) {
            auto rows = doc.GetColumn<std::string>(x);  
            for (int y = 0; y < gridSize; y++) {
                auto data = split(rows[y], ",");
                int slotId = std::stoi(data[0]);
                int talentId = std::stoi(data[1]);
                bool hidden = data[2] == "true";

                auto slot = new Talent(*slots[slotId]);
                auto talent = new Talent(*talents[talentId]);

                slot->hidden = !hidden;

                ply->grid->slotGrid[x][y] = slot;
                ply->grid->talentGrid[x][y] = talentId == 0 ? nullptr : talent;
            }
        }
    }

    //Character *ply = new Character();

    std::cout << ply->grid->ToString();
    std::cout << ply->GetEnergy().ToString();



/*

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

        std::cout << "You have 3 spells.\n\tSpell 1: " << player->spells[0]->ToString() << "\n\tSpell 2: " << player->spells[1]->ToString() << "\n\tSpell 3: " << player->spells[2]->ToString() << "\n";

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

*/
    return 0;
}

/*

me: cast? fire, ice, light
enemy: 


*/