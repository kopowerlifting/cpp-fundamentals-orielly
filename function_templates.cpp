// function_templates.cpp
#include <iostream>
#include "maximum.h" // include definition of function template maximum
using namespace std;

int main() {
    // demonstrate maximum with int values
    cout << "Input three integer values: ";
    int int1, int2, int3;
    cin >> int1 >> int2 >> int3;

    // invoke int version of maximum
    cout << "\nThe maximum integer value is: "
        << maximum(int1, int2, int3);

    // demonstrate maximum with double values
    cout << "\n\nInput three double values: ";
    double double1, double2, double3;
    cin >> double1 >> double2 >> double3;

    // invoke maximum with double values
    cout << "\nThe maximum double value is: "
        << maximum(double1, double2, double3);

    // demonstrate maximum with char values
    cout << "\n\nInput three char values: ";
    char char1, char2, char3;
    cin >> char1 >> char2 >> char3;

    // invoke maximum with char values
    cout << "\nThe maximum char value is: "
        << maximum(char1, char2, char3);
}