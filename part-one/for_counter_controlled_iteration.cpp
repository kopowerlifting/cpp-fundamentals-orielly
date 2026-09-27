// 2_counter_controlled_iteration.cpp
// Counter-controlled iteration with the while iteration statement.
#include <iostream>
using namespace std;

int main() {
    // for statement header includes initialization,
    // loop-continuation condition and increment
    for (int counter{1}; counter <= 10; ++counter) {
        cout << counter << " ";
    }

    // additional examples
    cout << "\n\nVary control variable from 1 to 100 in increments of 1:\n";
    
    for (int i{1}; i <= 100; ++i) {
        cout << i << " ";
    }

    cout << "\n\nVary control variable from 100 down to 1 in decrements of 1:\n";

    for (int i{100}; i >= 1; --i) {
        cout << i << " ";
    }

    cout << "\n\nVary control variable from 7 to 77 in increments of 7:\n";

    for (int i{7}; i <= 77; i += 7) {
        cout << i << " ";
    }

    cout << "\n\nVary control variable from 20 down to 2 in decrements of 2:\n";

    for (int i{20}; i >= 2; i -= 2) {
        cout << i << " ";
    }

    cout << "\n\nVary control variable over the values 2, 5, 6, 11, 14, 17, 20\n";

    for (int i{2}; i <= 20; i += 3) {
        cout << i << " ";
    }

    cout << "\n\nVary control variable over the values 99, 88, 77 ... 0\n";

    for (int i{99}; i >= 0; i -= 11) {
        cout << i << " ";
    }

    cout << "\n";
}