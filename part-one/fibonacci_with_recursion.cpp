// fibonacci_with_recursion.cpp
// Recursive function fibonacci.
#include <format>
#include <iostream>
using namespace std;

long fibonacci(long number); // function prototype

// fibonacci  n-1 + n-2

int main() { 
    // calculate the fibonaccis of 0 through 10
    for (int counter{0}; counter <= 10; ++counter) {
        cout << format("fibonacci({}) = {}\n", 
            counter, fibonacci(counter));
    }

    // display fibonaccis of 20, 30, and 40
    cout << format("\nfibonacci(20) = {}\n", fibonacci(20))
        << format("fibonacci(30) = {}\n", fibonacci(30))
        << format("fibonacci(40) = {}\n", fibonacci(40));
}

// recursive definition of function fibonacci
long fibonacci(long number) {
    if ((0 == number) || (1 == number)) { // test for base case
        return number;
    }
    else { // recursion step
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}
