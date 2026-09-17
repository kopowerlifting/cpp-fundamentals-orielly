// pass_by_reference.cpp
// Pass by reference example
#include <iostream>
using namespace std;

int squareByValue(int number);
void squareByReference(int& numberRef);

int main() {
    int x{2};
    int z{4};

    cout << "x = " << x;
    cout << "\nx squared = " << squareByValue(x);
    cout << "\nx = " << x;

    cout << "\n\nz = " << z;
    squareByReference(z);
    cout << "\nz squared = " << z;
}

int squareByValue(int number) {
    return number *= number;
}
void squareByReference(int& numberRef) {
    numberRef *= numberRef;
}