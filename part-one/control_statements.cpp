// control_statements.cpp
// 
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::boolalpha;

// keywords C and C++
// asm auto break case char
// const continue default do double
// else enum extern float for
// goto if inline int long
// register return short signed sizeof
// static struct switch typedef union
// unsigned void volatile

// C++ only
// alignas alignof and and_eq bitand
// bitor bool catch char16_t char32_t
// class compl const_cast constexpr decltype
// delete dynamic_cast explicit export false
// friend mutable namespace new noexcept
// not not_eq nullptr operator or
// or_eq private protected public reinterpret_cast
// static_assert static_cast template this thread_local
// throw true try typeid typename
// using virtual wchar_t xor xor_eq

// C++ 20 additions
// char8_t concept char16_t consteval constinit
// co_await co_return co_yield requires

int main() {

    int studentGrade{0};

    cout << "Enter your grade to find out if you have passed: ";
    cin >> studentGrade;

    if (studentGrade >= 60) {
        cout << "Passed\n";
    } 
    else {
        cout << "Failed\n";
    }

    if (studentGrade >= 90) {
        cout << "A\n";
    }
    else if (studentGrade >= 80) {
        cout << "B\n";
    }
    else if (studentGrade >= 70) {
        cout << "C\n";
    }
    else if (studentGrade >= 60) {
        cout << "D\n";
    }
    else {
        cout << "F\n";
    }

    // ternary operator Conditional ?:
    cout << (studentGrade >= 60 ? "Passed\n" : "Failed\n");

    // while iteration statement

    int product {3};

    while (product <= 100) {
        product = 3 * product;
        cout << "Current product: " << product << "!\n";
    }
    
}