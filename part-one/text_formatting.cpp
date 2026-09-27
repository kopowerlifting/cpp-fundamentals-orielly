// text_formatting.cpp
// Summing integers with the for statement; introducing text formatting
#include <format>
#include <iostream>
using namespace std;

int main() {
    int total{0};

    // total even intergers from 2 through 20
    for (int number{2}; number <= 20; number +=2) {
        total += number;
    }

    cout << format("Sum is {}\n", total);
}