#pragma once

#include <vector>
#include <string>
#include "Talent.h"

class TalentGrid {
public:
    TalentGrid();
    std::vector<std::vector<Talent*>> talentGrid;
    std::vector<std::vector<Talent*>> slotGrid;
    std::string toString();
    int gridSize = 2;    
    float Calculate();
};
