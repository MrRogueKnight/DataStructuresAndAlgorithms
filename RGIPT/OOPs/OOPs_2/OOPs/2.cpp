#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(time(0));
    int actualNumber = rand() % 100 + 1;
    int guess;
    int trials = 3;

    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "You have " << trials << " trials to guess it!" << endl << endl;

    for (int attempt = 1; attempt <= trials; attempt++) {
        cout << "Trial " << attempt << ": Enter your guess (1-100): ";

        while (!(cin >> guess) || guess < 1 || guess > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 100: ";
        }

        if (guess == actualNumber) {
            cout << "Congratulations! You guessed the correct number: " << actualNumber << endl;
            break;
        }
        else if (guess > actualNumber) {
            cout << "Your guess is HIGHER than the actual number." << endl;
        }
        else {
            cout << "Your guess is LOWER than the actual number." << endl;
        }

        if (attempt == trials) {
            cout << "Game over! You've used all your trials." << endl;
            cout << "The actual number was: " << actualNumber << endl;
        }
        else {
            cout << "Try again!" << endl << endl;
        }
    }

    return 0;
}