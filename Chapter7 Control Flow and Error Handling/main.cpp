#include <iostream>
#include <random>
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getRandOneThroughOneHundred() {
    std::random_device rd;
    std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ ss };
    std::uniform_int_distribution d100{ 1, 100 };

    return d100(mt);
}

int getGuess(int cnt) {
    while (true) {
        std::cout << "Guess #" << cnt << ":";
        int guess{};
        std::cin >> guess;

        // Check for failed extraction
        if (!std::cin) {
            std::cin.clear();   // put us back in 'normal' operation mode
            ignoreLine();
            std::cerr << "Oops, that input is valid. Please try again.\n";
        } else if (guess > 100 || guess < 1){
            ignoreLine();
            std::cerr << "Oops, that input is out of range. Please try again.\n";
        } else {
            ignoreLine();
            return guess;
        }
    }
}

bool playGame(int guesses, int number) {
    // Loop through all of guesses
    for (int cnt{ 1 }; cnt <= guesses; ++cnt) {
        int guess{ getGuess(cnt) };

        if (guess < number) {
            std::cout << "Your guess is too low\n";
        } else if (guess > number) {
            std::cout << "Your guess is too high\n";
        } else {    // guess == number
            return true;
        }
    }

    return false;
}

bool playAgain() {
    while (true) {
        std::cout << "Would you like to play again(y/n)?";
        char ch{};
        std::cin >> ch;

        switch (ch) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                break;
        }

        ignoreLine();   // ignore any extraneous input
    }
}

int main() {
    constexpr int guesses{ 7 }; // the user has this many guesses

    do {
        int number{ getRandOneThroughOneHundred() };
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

        bool won{ playGame(guesses, number) };
        if (won) {
            std::cout << "Correct! You win!\n";
        } else {
            std::cout << "Sorry, you lose. The correct number was " << number << "\n";
        }
    } while (playAgain());

    std::cout << "Thank you for playing." << '\n';

    return 0;
}