#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number game!";
    std::cout << "I have chosen a number between 1 and 100, try to guess what it is.";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "It is too low! Try again.";
        } else if (guess > secretNumber) {
            std::cout << "It is too high! Try again.";
        } else {
            std::cout << "Congratulations! You guessed the number for yourself in at most " << attempts << " attempt(s).";
        }

    } while (guess != secretNumber);

    return 0;
}