#include "Game.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

Game::Game() : Game(1, 100, 10) {}

Game::Game(int minValue, int maxValue, int maxAttempts)
    : minValue(minValue),
      maxValue(maxValue),
      maxAttempts(maxAttempts),
      attemptsUsed(0),
      secret(0) {
    if (this->minValue > this->maxValue) {
        std::swap(this->minValue, this->maxValue);
    }

    if (this->maxAttempts <= 0) {
        this->maxAttempts = 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    this->secret = this->pickSecret();
}

Game::~Game() = default;

int Game::pickSecret() const {
    if (minValue == maxValue) {
        return minValue;
    }

    return minValue + (std::rand() % (maxValue - minValue + 1));
}

int Game::checkGuess(int guess) const {
    if (guess == secret) {
        return 0;
    }
    if (guess < secret) {
        return -1;
    }
    return 1;
}

void Game::play() {
    std::cout << "Guess the number between " << minValue << " and " << maxValue
              << ". You have " << maxAttempts << " attempts.\n";

    while (attemptsUsed < maxAttempts) {
        std::cout << "Attempt " << attemptsUsed + 1 << " of " << maxAttempts
                  << ": Enter your guess: ";

        int guess = reader.readGuess(minValue, maxValue);
        ++attemptsUsed;

        int result = checkGuess(guess);
        if (result == 0) {
            std::cout << "Correct! You guessed the secret number " << secret << ".\n";
            return;
        }

        if (result < 0) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "Too high!\n";
        }
    }

    std::cout << "You ran out of attempts. The secret number was " << secret << ".\n";
}
