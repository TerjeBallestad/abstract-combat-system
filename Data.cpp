
#include "Data.h"
#include "rapidcsv.h"

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


std::vector<Talent *> LoadTalents() 
{
    std::vector<Talent*> talents;
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
                CharToBaseType(North[i]), 
                CharToBaseType(East[i]), 
                CharToBaseType(South[i]), 
                CharToBaseType(West[i])
            )
        );
    }
    return talents;
}


std::vector<Talent *> LoadSlots() 
{
    std::vector<Talent*> slots;
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
                CharToBaseType(North[i]), 
                CharToBaseType(East[i]), 
                CharToBaseType(South[i]), 
                CharToBaseType(West[i])
            )
        );
    }
    return slots;
}

void LoadToGrid(std::vector<Talent*> talents, std::vector<Talent*> slots, TalentGrid *grid) {
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

            grid->slotGrid[x][y] = slot;
            grid->talentGrid[x][y] = talentId == 0 ? nullptr : talent;
        }
    }
}

std::vector<Spell *> LoadSpells(){
    std::vector<Spell *> spells;
    rapidcsv::Document doc("./Spells-Spells.csv", rapidcsv::LabelParams(0,-1), rapidcsv::SeparatorParams(';'));
     auto Id = doc.GetColumn<int>("Id");
    auto Name = doc.GetColumn<std::string>("Name");
    auto L = doc.GetColumn<std::string>("L");
    auto B = doc.GetColumn<std::string>("B");
    auto D = doc.GetColumn<std::string>("D");
    auto R = doc.GetColumn<std::string>("R");
    auto G = doc.GetColumn<std::string>("G");

   for (auto row : Id) {
        auto i = row;
        spells.push_back(
            new Spell(
                Name[i],
                * new BTVector(
                    CharToBaseType(L[i]), 
                    CharToBaseType(B[i]), 
                    CharToBaseType(D[i]), 
                    CharToBaseType(R[i]),
                    CharToBaseType(G[i])
                )
            )
        );
    }
    return spells;
};

void LoadSpellsToCharacter(std:: vector<Spell*> spells, Character* character){
    rapidcsv::Document doc("./Spells-Characters.csv", rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(';'));
    auto spellIDs = doc.GetColumn<std::string>(character->name);
    int length = *(&character->spells + 1) -character->spells;
     for (int i = 0; i < length; i++)
     {
         try {
            int id = stoi(spellIDs[i]);
            character->spells[i] = new Spell(*spells[id]);
         } catch (const std::invalid_argument & e) {
             
         }

     }
     
};