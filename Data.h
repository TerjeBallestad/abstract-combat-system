#pragma once

#include <vector>
#include "Talent.h"
#include "TalentGrid.h"
#include "Spell.h"
#include "Character.h"

std::vector<Talent *> LoadTalents();
void LoadToGrid(std::vector<Talent*> talents, std::vector<Talent*> slots, TalentGrid *grid);
void LoadSpellsToCharacter(std:: vector<Spell*> spells, Character* character);
std::vector<Talent *> LoadSlots();
std::vector<Spell *> LoadSpells();