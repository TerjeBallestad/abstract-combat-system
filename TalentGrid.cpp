#include "Talent.h"
#include "TalentGrid.h"
#include "Util.h"
#include "ACS.h"

TalentGrid::TalentGrid() {
    talentGrid.resize(gridSize);
    slotGrid.resize(gridSize);
    for (auto & row: talentGrid) {
        row.resize(gridSize);
    }
    for (auto & row: slotGrid) {
        row.resize(gridSize);
    }
}

float TalentGrid::Calculate() {
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

    return 0;
}

string TalentGrid::toString() {
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
