#include <vector>
#include "Talent.h"

class TalentGrid {
public:
    TalentGrid();
    vector<vector<Talent*>> talentGrid;
    vector<vector<Talent*>> slotGrid;
    string toString();
    int gridSize = 2;    
    float Calculate();
};
