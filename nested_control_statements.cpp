// nested_control_statements.cpp
// Analysis of examination results using nested control statements
#include <iostream>
using namespace std;

int main() {
    // initializing variables in declarations
    int passes{0};
    int failures{0};
    int studentCounter{1};

    // process 10 students using counter-controlled loop
    while (studentCounter <=10) {
        // prompt user for input and obtain value from user
        cout << "Enter result (1 = pass, 2 = fail): ";
        int result;
        cin >> result;

        // if...else is nested in the while statmeent
        if (result == 1) {
            passes = passes + 1;
        }
        else {
            failures = failures + 1;
        }

        // increment studentCounter so loop eventually termintes
        studentCounter = studentCounter + 1;
   }
    // termination phase; perpare and display results
    cout << "Passed: " << passes << "\nFailed: " << failures << "\n";
    
    if (passes > 8) {
        cout << "Bonus to the instructor!";
    }
}