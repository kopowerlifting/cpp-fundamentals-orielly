// sentinel_controlled_iteration.cpp
// Solving the class-average program using sentinel controlled iteration
#include <iostream>
#include <iomanip> // paramaterized stream manipulators

using std::cout;
using std::cin;

int main() {
    double total{0.0}; // initialize sum of grades
    int gradeCounter{0}; // initialize # of grades entered so far

    // processing phase
    // prompt for input and read grade from user
    cout << "Enter grade or -1 to quit: ";
    int grade;
    cin >> grade;

    // loop until sentinel value is read from user
    while (grade != -1) {
        total = total + grade; // add grade to total
        gradeCounter = gradeCounter + 1; // increment counter

        // prompt for input and read next grade from user
        cout << "Enter grade or -1 to quit: ";
        cin >> grade;
    }

    // termination phase 
    // if user entered at least one grade
    if (gradeCounter != 0) { // avoid division by zero
        // calculate average of grades
        double average{total / gradeCounter};

        // display total and average (with two digits of precision)
        cout << "\nTotal of the " << gradeCounter
            << " grades entered is " << total;
        cout << std::setprecision(2) << std::fixed; // fixed, exponention, scientific etc 
        cout << "\nClass average is " << average << "\n";
    }
    else { // no grades were entered, so output appropriate message
        cout << "No grades were entered\n";
    }

    return 0;
}