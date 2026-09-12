// supersized_integers.cpp
// Conveniently creating and manipulating super-sized integers
//  with objects of the Boost Multiprecision library's cpp_int class.

// RSA Public-Key cryptography uses enormous prime numbers
// two numbers multiplied together 19 decimal digits

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost:multiprecisions::cpp_int;

int main() {
    // initializing cpp_ints
    const cpp_int value1{"100000000000000000000000000000"}; // 30 digits
    const cpp_int value2{9223372036854775807LL}; // long lon max
    const int value3{3};

    cout << "INITIAL VALUES"
        << "\ncpp_int value1: " << value1
        << "\ncpp_int value2: " << value2
        << "\ncpp_int value3: " << value3;


    // arithmetic with cpp_ints
    cout << "\n\nADD, SUBTRACT AND MULTIPLY CPP_INT OBJECTS"

}
