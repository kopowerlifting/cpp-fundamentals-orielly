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

    cout << "\n";
}