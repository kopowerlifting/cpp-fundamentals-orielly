// increment_decrement_operators.cpp
// Prefix increment and postfix increment operators
#include <iostream>
using namespace std;

int main() {
    //demonstrate postfix increment operator
    int c{5};
    cout << "c before postincrement:" << c << "\n";
    cout << " postincrementing c: " << c++ << "\n";
    cout << " c after postincrement " << c << "\n";

    cout << "\n";

    // demonstrate prefix increment operator
    c = 5;
    cout << "c before preincrement:" << c << "\n";
    cout << " preincrementing c: " << ++c << "\n";
    cout << " c after preincrement " << c << "\n";
}