// pointer_operations.cpp
#include <iostream>
#include <format>

void cubeByReference(int* nPtr); // prototype

int main() {
    int y{5};
    int* yPtr{nullptr}; // pointer to nothing
    yPtr = &y;

    std::cout << "This is the address of the yPtr " << yPtr << '\n';
    std::cout << "This is the value of the yPtr " << *yPtr << '\n';

    // Pass by reference with pointers example
    int number{5};

    std::cout << std::format("Original value of number is {}\n", number);
    cubeByReference(&number); // pass number address to cubeByReference
    std::cout << std::format("New value of number is {}\n", number);

}

void cubeByReference(int* nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
}

