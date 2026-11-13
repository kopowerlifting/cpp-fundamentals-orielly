// size_of_operator.cpp
// Sizeof operator when used on built-in array's name
// returns the number of bytes in the built-in array.
#include <format>
#include <iostream>

size_t getSize(double* ptr); // prototype
size_t getSizeRef(double (&values)[20]); // prototype

int main() {
    double numbers[20]; // 20 doubles; occupies 160 bytes on our system

    std::cout << std::format("Number of bytes in numbers is {}\n",
        sizeof(numbers));

    std::cout << std::format("Number of bytes returned by getSize is {}\n",
        getSize(numbers));
}

// return size of ptr
size_t getSize(double* ptr) {
    return sizeof(ptr); // size of pointer, not the array
}
