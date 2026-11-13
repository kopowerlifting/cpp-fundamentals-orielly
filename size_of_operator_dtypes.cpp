// size_of_operator_dtypes.cpp
// sizeof operator used to determine standard data type sizes.
#include <format>
#include <iostream>

int main() {
    constexpr char c{}; // variable of type char
    constexpr short s{}; //variable of type short
    constexpr int i{}; // variable of type int
    constexpr long l{}; // variable of type long
    constexpr long long ll{}; // variable of type long long
    constexpr float f{}; // variable of type float
    constexpr double d{}; // variable of type double
    constexpr long double ld{}; // variable of type long double
    constexpr int array[20]{}; // variable of type int array
    const int* const ptr{array}; // variable of type pointer to const int

    std::cout << std::format("Size of char is {} bytes\n", sizeof(c));
    std::cout << std::format("Size of short is {} bytes\n", sizeof(s));
    std::cout << std::format("Size of int is {} bytes\n", sizeof(i));
    std::cout << std::format("Size of long is {} bytes\n", sizeof(l));
    std::cout << std::format("Size of long long is {} bytes\n", sizeof(ll));
    std::cout << std::format("Size of float is {} bytes\n", sizeof(f));
    std::cout << std::format("Size of double is {} bytes\n", sizeof(d));
    std::cout << std::format("Size of long double is {} bytes\n", sizeof(ld));
    std::cout << std::format("Size of int array is {} bytes\n", sizeof(array));
    std::cout << std::format("Size of pointer is {} bytes\n", sizeof(ptr));
}