// maximum_function.cpp
// maximum function with a function prototype
#include <iostream>
using namespace std;

int maximum(int x, int y, int z); // function prototype

int main() {
    cout << "Enter three integer values: ";
    int int1, int2, int3;
    cin >> int1 >> int2 >> int3;

    // invoke maximum
    cout << "The maximum integer value is: "
        << maximum(int1, int2, int3) << '\n';
}

// returns the largest of three integers
int maximum(int x, int y, int z) {
    int maximumValue{x}; // assume x is the largest to start
    
    // determine whether y is greate than maximumValue
    if (y > maximumValue) {
        maximumValue = y; 
    }

    if (z > maximumValue) {
        maximumValue = z;
    }

    return maximumValue;
}