// supersized_integers.cpp
// Conveniently creating and manipulating super-sized integers
//  with objects of the Boost Multiprecision library's cpp_int class.

// RSA Public-Key cryptography uses enormous prime numbers
// two numbers multiplied together 19 decimal digits

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

int main() {
    // initializing cpp_ints
    const cpp_int value1{"100000000000000000000000000000"}; // 30 digits
    const cpp_int value2{numeric_limits<long long>::max()}; // long long max
    const int value3{3};

    cout << "INITIAL VALUES"
        << "\ncpp_int value1: " << value1
        << "\ncpp_int value2: " << value2
        << "\ncpp_int value3: " << value3;


    // arithmetic with cpp_ints
    cout << "\n\nADD, SUBTRACT AND MULTIPLY CPP_INT OBJECTS"
        << "\nvalue1 + value2: " << value1 + value2
        << "\nvalue1 - value2: " << value1 - value2
        << "\nvalue1 * value2: " << value1 * value2;

    // arithmetic mixing cpp_ints and integers
    cout << "\n\nMULTUPLY A CPP_INT OBJECT BY INT VALUES"
        << "\nvalue1 * value3: " << value1 * value3
        << "\n    value1 * 17: " << value1 * 17 << "\n";
    
    return 0;
}
