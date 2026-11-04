#ifndef GAME_H
#define GAME_H

#include "inReader.h" // Include the InReader class for input handling

class Game {
public:
    Game(); // Constructor
    Game(int minValue, int maxValue, int maxAttempts);
    void play(); // Plays the game
    ~Game(); // Destructor
    void play(); // Plays the game

private:
    InReader reader; // Instance of InReader for handling input
    int minValue; // Minimum value for the game
    int maxValue; // Maximum value for the game
    int maxAttempts; // Maximum number of attempts allowed
    int attemptsUsed;    // How many guesses have been made so far.
    int secret; // The secret number the player is trying to guess

    int pickSecret() const; // Picks a secret number within the range [minValue, maxValue]
    int checkGuess(int guess) const; // Checks if the given guess is correct, too high, or too low
};

#endif // GAME_H

