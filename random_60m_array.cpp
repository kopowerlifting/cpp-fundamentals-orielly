// random_60m.cpp
// Rolling a six-sided die randomly 60,000,000 times, using array instead of switch.
#include <format>
#include <iostream>
#include <random> // contains random-number generation features
#include <array>

int main() {
    // setup random-number generation
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution randomDie{1, 6};

    constexpr size_t arraySize{7}; // ignore element zero
    std::array<int, arraySize> frequency{}; //initialize to 0s


    // summarize results of 60,000,000 rolls of a die
    for (int roll{1}; roll <= 60'000'000; ++roll) {
        ++frequency.at(randomDie(engine));
    }

    std::cout << std::format("{:>4}{:>13}\n", "Face", "Frequency"); // headers
    for (size_t face{1}; face < frequency.size(); ++face) {
        std::cout << std::format("{:>4d}{:>13d}\n", face, frequency.at(face));
    }
}