#ifndef GAME_H
#define GAME_H

#include "inReader.h" // Include the InReader class for input handling

class Game {
public:
    Game(); // Constructor
    ~Game(); // Destructor
    void play(); // Plays the game

private:
    InReader reader; // Instance of InReader for handling input
};

#endif // GAME_H

