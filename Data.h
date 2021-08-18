#pragma once

#include <vector>
#include "Talent.h"
#include "TalentGrid.h"

std::vector<Talent *> LoadTalents();
void LoadToGrid(std::vector<Talent*> talents, std::vector<Talent*> slots, TalentGrid *grid);
std::vector<Talent *> LoadSlots();