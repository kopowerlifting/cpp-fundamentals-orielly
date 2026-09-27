// compounding_interest.cpp
// This program calculates the future value of an investment based on compound interest.
#include <iostream>
#include <cmath>
#include <format>
using namespace std;

int main() {
    double principal{1000.00}; // initial amount before interest
    double rate{0.05}; // interest rate

    cout << format("Initial principal: {:>7.2f}\n", principal)
        << format("     Interest rate: {:7.2f}\n", rate);
      
    // display headers
    cout << format("\n{}{:>20}\n", "Year", "Amount on deposit");

    // calculate amount on deposit for each year
    for (int year{1}; year <= 10; ++year) {
       double amount{principal * pow(1.0 + rate, year)};

    // display the year and the amount
    cout << format("{:>4d}{:>20.2f}\n", year, amount);
    }
}