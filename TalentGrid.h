#pragma once

#include <vector>
#include <string>
#include "Talent.h"
#include "BTVector.hpp"

class TalentGrid {
public:
    TalentGrid();
    std::vector<std::vector<Talent*>> talentGrid;
    std::vector<std::vector<Talent*>> slotGrid;
    std::string ToString();
    int gridSize = 16;    
    BTVector GetEnergy();
};
