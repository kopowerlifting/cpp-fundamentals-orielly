// inline_functions.cpp
// inline function that calculates the volume of a cube
#include <iostream>
using namespace std;

// Definition of inline function cube. Definition of function appears
// before function is called, so a function prototype is not required.
// First line of function definitiion also acts as a prototype.
inline double cube(double side) {
    return side * side * side; // calculate cube
}

int main () {
    double sideValue; // stores value entered by user
    cout << "Enter the side length of your cube: ";
    cin >> sideValue; // read value from user

    // calculate cube of sideValue and display result
    cout << "Volume of cube with side "
        << sideValue << " is " << cube(sideValue) << '\n';
}