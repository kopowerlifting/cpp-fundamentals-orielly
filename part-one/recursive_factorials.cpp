// recursive_factorials.cpp
// This program demonstrates a recursive function that calculates the factorial of a number.
#include <boost/multiprecision/cpp_int.hpp>
#include <format>
#include <iostream>
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int factorial(int number); // function prototype

// factorial n! = n * (n - 1)

int main() { 
    // calculate the factorials of 0 through 10
    for (int counter{0}; counter <= 10; ++counter) {
        cout << format("{:>2}! = ", counter) << factorial(counter) << "\n";
    }

    // display factorials of 20, 30, and 40
    cout << format("\n{:>2}! = ", 20) << factorial(20)
        << format("\n{:>2}! = ", 30) << factorial(30)
        << format("\n{:>2}! = ", 40) << factorial(40);
}

// recursive definition of function factorial
cpp_int factorial(int number) {
    if (number <=1) { // test for base case
        return 1; // base cases: 0! = 1 and 1! = 1
    }
    else { // recursion step
        return number * factorial(number - 1);
    }
}
