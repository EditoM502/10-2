#include "inReader.h"

#include <iostream>
#include <limits>

int InReader::readGuess(int min, int max) {
    int guess = 0;

    while (true) {
        if (!(std::cin >> guess)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a whole number.\n";
            continue;
        }

        if (guess < min || guess > max) {
            std::cout << "Guess must be between " << min << " and " << max << ".\n";
            continue;
        }

        return guess;
    }
}
