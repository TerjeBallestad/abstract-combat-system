#include <iostream>
#include <ctime>

enum PersonalityType { white, black, blue, red, green };

struct PuzzlePiece {
    int ID;
    PersonalityType north, south, east, west;
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



int main () 
{
    srand(time(0));

    std::cout << "Hello world " << rand();
    return 0;
}