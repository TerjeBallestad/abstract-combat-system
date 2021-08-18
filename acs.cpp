#include <iostream>
#include <ctime>
#include "acs-character.h"
#include "acs-damage.h"
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using std::string;
using std::vector;

enum BaseType { white, black, blue, red, green, none };

string Enum2Color(BaseType color) {
    if (color == white) {
        return string("\u001b[37m");
    } else if (color == black) {
        return string("\u001b[30m");
    } else if (color == blue) {
        return string("\u001b[34m");
    } else if (color == red) {
        return string("\u001b[31m");
    } else if (color == green) {
        return string("\u001b[32m");
    }
}

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

class Talent {
public:
    string name = string("no talent");
    int energyPerTurn = 0;
    BaseType north, south, east, west;
    Talent(string name_, int energyPerTurn_, BaseType n,BaseType s,BaseType e,BaseType w) {
        north = n;
        south = s;
        east = e;
        west = w;
        name = name_;
        energyPerTurn = energyPerTurn_;
        
    }
    string toString() {
        return name;
    }
};

/*
     *
    *c**J
     * 
*/

class TalentGrid {
public:
    vector<vector<Talent*>> talentGrid;
    vector<vector<Talent*>> slotGrid;

    int gridSize = 2;

    TalentGrid() {
        talentGrid.resize(gridSize);
        slotGrid.resize(gridSize);
        for (auto & row: talentGrid) {
            row.resize(gridSize);
        }
        for (auto & row: slotGrid) {
            row.resize(gridSize);
        }
    }
    
    float Calculate() {
        int scoreWhite = 0;
        int scoreBlack = 0;
        int scoreRed = 0;
        int scoreGreen = 0;
        int scoreBlue = 0;

        for (int x = 0; x < gridSize; x++) {
            for (int y = 0; y < gridSize; y++) {
                auto talent = talentGrid[y][x];
                
                if (talent) {
                    if (talent->west == white) {
                        scoreWhite += talent->energyPerTurn;
                    } else if (talent->west == black) {
                        scoreBlack += talent->energyPerTurn;
                    } else if (talent->west == red) {
                        scoreRed += talent->energyPerTurn;
                    } else if (talent->west == blue) {
                        scoreBlue += talent->energyPerTurn;
                    } else if (talent->west == green) {
                        scoreGreen += talent->energyPerTurn;
                    }
                }
            }
        }
    }

    auto toString() {
        vector<string> strings;
        
        int subGridSize = 3;
        size_t size = (gridSize * gridSize) * subGridSize*subGridSize;
        strings.resize(size);

        for (int i = 0; i < size; i++) {
            auto gridX = (i / (subGridSize)) % gridSize;
            auto gridY = (i / (subGridSize*subGridSize) / gridSize) % gridSize;
            
            auto talent = talentGrid[gridY][gridX];
            auto slot = slotGrid[gridY][gridX];
            
            auto subX = i%subGridSize;
            auto subY = (i / (subGridSize*gridSize))%subGridSize;
            
            if (talent) {

                if (subX == 1 && subY == 1) {
                    strings[i] = talent->toString();   
                } else if (subX == 1 && subY == 0) {
                    strings[i] = Enum2Color(talent->north) + "˰" + Enum2Color(white);
                } else if (subX == 1 && subY == 2) {
                    strings[i] = Enum2Color(talent->south) + "ˇ" + Enum2Color(white);
                } else if (subX == 0 && subY == 1) {
                    strings[i] = Enum2Color(talent->west) + "˂" + Enum2Color(white);
                } else if (subX == 2 && subY == 1) {
                    strings[i] = Enum2Color(talent->east) + "˃" + Enum2Color(white);
                } else if (subX == 0 && subY == 0) {
                    strings[i] = "⌜";
                } else if (subX == 2 && subY == 0) {
                    strings[i] = "⌝";
                } else if (subX == 0 && subY == 2) {
                    strings[i] = "⌞";
                } else if (subX == 2 && subY == 2) {
                    strings[i] = "⌟";
                }
            } else {
                if (subX == 1 && subY == 1) {
                    strings[i] = "·";
                } else if (subX == 1 && subY == 0) {
                    if (slot->north == none) {
                        strings[i] = "·";
                    } else {
                        strings[i] = Enum2Color(slot->north) + "˰" + Enum2Color(white);
                    }
                } else if (subX == 1 && subY == 2) {
                    if (slot->south == none) {
                        strings[i] = "·";
                    } else {
                        strings[i] = Enum2Color(slot->south) + "ˇ" + Enum2Color(white);
                    }
                } else if (subX == 0 && subY == 1) {
                    if (slot->west == none) {
                        strings[i] = "·";
                    } else {
                        strings[i] = Enum2Color(slot->west) + "˂" + Enum2Color(white);
                    }
                } else if (subX == 2 && subY == 1) {
                    if (slot->east == none) {
                        strings[i] = "·";
                    } else {
                        strings[i] = Enum2Color(slot->east) + "˃" + Enum2Color(white);
                    }
                } else if (subX == 0 && subY == 0) {
                    strings[i] = "⌜";
                } else if (subX == 2 && subY == 0) {
                    strings[i] = "⌝";
                } else if (subX == 0 && subY == 2) {
                    strings[i] = "⌞";
                } else if (subX == 2 && subY == 2) {
                    strings[i] = "⌟";
                }
            }

            if (i % (subGridSize*gridSize) == (subGridSize*gridSize)-1) {
               strings[i] += "\n";
            }
        }

        string str;

        for(size_t i=0;i!=strings.size();++i)
            str += strings[i];

        return str;
    }
};

int main () 
{
    srand(time(0));

    #define x nullptr
    #define T new Talent("T", 1, blue, blue, blue, blue)
    #define C new Talent("C", 2, white, white, white, white)
    #define J new Talent("J", 1, red, blue, red, blue)

    TalentGrid grid;
    grid.slotGrid = {
        {new Talent(" ", 0, red, none, none, black), new Talent(" ", 0, black, none, black, none)},
        {new Talent(" ", 0,none, blue, none, red), new Talent(" ", 0, none, blue, red, none)},
    };

    grid.talentGrid = {
        {x, T},
        {C, x},
    };

    #undef x

    std::cout << grid.toString();

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

*/
    return 0;
}

/*

me: cast? fire, ice, light
enemy: 


*/