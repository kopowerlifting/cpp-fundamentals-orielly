// logical_operators.cpp
// Logical operators example
#include <format>
#include <iostream>
using namespace std;

int main () {
    // create truth table for && (logical AND operator)
    cout << "Logical AND (&&)\n"
        << format("false && false {}\n", false && false)
        << format("false && true {}\n", false && true)
        << format("true && false {}\n", true && false)
        << format("true && true {}\n\n", true && true);

    // create truth table for || (logical OR) operator
    cout << "Logical OR (||)\n"
        << format("false || false {}\n", false || false)
        << format("false || true {}\n", false || true)
        << format("true || false {}\n", true || false)
        << format("true || true {}\n\n", true || true);

    // create truth table for ! (logical negation) operator
    cout << "Logical negation (!)\n"
        << format("!false: {}\n", !false)
        << format("!true {}\n", !true);
}