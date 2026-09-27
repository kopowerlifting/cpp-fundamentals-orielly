// random_60m.cpp
// Rolling a six-sided die randomly 60,000,000 times.
#include <format>
#include <iostream>
#include <random> // contains random-number generation features
using namespace std;

int main() {
    // setup random-number generation
    default_random_engine engine{};
    uniform_int_distribution randomDie{1, 6};

    int frequency1{0}; // count of 1s rolled
    int frequency2{0}; // count of 2s rolled
    int frequency3{0}; // count of 3s rolled
    int frequency4{0}; // count of 4s rolled
    int frequency5{0}; // count of 5s rolled
    int frequency6{0}; // count of 6s rolled

    // summarize results of 60,000,000 rolls of a die
    for (int roll{1}; roll <= 60'000'000; ++roll) {
        switch (const int face{randomDie(engine)}) {
            case 1:
                ++frequency1;
                break;
            case 2:
                ++frequency2;
                break;
            case 3:
                ++frequency3;
                break;
            case 4:
                ++frequency4;
                break;
            case 5:
                ++frequency5;
                break;
            case 6:
                ++frequency6;
                break;
            default: // invalid value
                cout << "Program should never get here!";
                break;
        }
    }

    cout << format("{:>4}{:>13}\n", "Face", "Frequency"); // headers
    cout << format("{:>4d}{:>13d}\n", 1, frequency1)
        << format("{:>4d}{:>13d}\n", 2, frequency2)
        << format("{:>4d}{:>13d}\n", 3, frequency3)
        << format("{:>4d}{:>13d}\n", 4, frequency4)
        << format("{:>4d}{:>13d}\n", 5, frequency5)
        << format("{:>4d}{:>13d}\n", 6, frequency6); 
}