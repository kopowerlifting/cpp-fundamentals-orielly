// craps.cpp
// A game of chance with random_device
#include <iostream>
#include <format>
#include <random>
using namespace std;

int rollDice(); // rolls dice

int main() {
    // scoped enumeration with constants that represent the game status
    enum class Status {keepRolling, won, lost};

    int myPoint{0}; // point if no win or loss on first roll
    Status gameStatus{Status::keepRolling}; // game is not over

    // determine game status and point (if needed) based on first roll
    switch (const int sumOfDice{rollDice()}) {
        case 7: // win with 7 on first roll
        case 11: // win with 11 on first roll
            gameStatus = Status::won;
            break;
        case 2: // lose with 2 on first roll
        case 3: // lose with 3 on first roll
        case 12: // lose with 12 on first roll
            gameStatus = Status::lost;
            break;
        default: // did not win or lose, so remember the point
            myPoint = sumOfDice; // remember the point
            cout << format("Point is {}\n", myPoint);
            break;
    }

    // while game is not complete
    while (Status::keepRolling == gameStatus) { // not won or lost
        // roll dice again and determine game status
        if (const int sumOfDice{rollDice()}; sumOfDice == myPoint) {
            gameStatus = Status::won;
        }
        else if (sumOfDice == 7) { // lose by rolling 7 before point
            gameStatus = Status::lost;
        }
    }

    // display won or lost message
    if (Status::won == gameStatus) {
        cout << "Player wins\n";
    }
    else {
        cout << "Player loses\n";
    }
}

    // roll dice, calculate sum and display results

    int rollDice() {
        // setup random-number generation
        static random_device rd; // used to seed the detault_random_enging
        static default_random_engine engine{rd()}; // rd()  produces a seed
        static uniform_int_distribution randomDie{1, 6};

        const int die1{randomDie(engine)}; // first die roll
        const int die2{randomDie(engine)}; // second die roll
        const int sum{die1 + die2}; // compute sum of die values

        // display results of this cell
        cout << format("PLayer rolled {} + {} = {}\n", die1, die2, sum);

        return sum;
    }

