// switch.cpp
// Multiple selection statement 
#include <iostream>
#include <format>
using namespace std;


int main() {
    double total{0.0}; // sum of grades
    int gradeCounter{0};
    int aCount{0};
    int bCount{0};
    int cCount{0};
    int dCount{0};
    int eCount{0};
    int fCount{0};


    cout << "Enter the integer grades in the range of 0-100.\n"
        << "Type the end-of-file indicator to terminate input:\n"
        << "   On UNIX/Linux/macOS type <Ctrl> d then press Enter\n"
        << "   On Windows type <Ctrl> z then press Enter\n";
        
    int grade;

    // lop until user enters the end-of-file indicator
    while (cin >> grade) {
        total += grade; // add grade to total
        ++gradeCounter;

        // increment appropriate letter-grade counter
        switch (grade / 10) {
            case 9: // grade was between 90
            case 10: // and 100, inclusive
                ++aCount;
                break; // exits switch

            case 8: //grade was between 80 and 89
                ++bCount;
                break;
            
            case 7: // grade was between 70 and 79
                ++cCount;
                break;
            
            case 6: // grade was between 60 and 69
                ++dCount;
                break;
            
            default: // grade was less than 60
                ++fCount;
                break;
        }
    }
    // display grade report
    cout << "\nGrade Report:\n";

    // if user entered at least one grade..
    if (gradeCounter != 0) {
        // calculate average of all grades entered
        double average{total / gradeCounter};

        // output summary of results
        cout << format("Total of the {} grades entered is {}\n",
                    gradeCounter, total)
            << format("Class average is {:.2f}\n\n", average)
            << "Summary of student's grades:\n"
            << format("A: {}\nB: {}\nC: {}\nD: {}\nE: {}\nF: {}\n",
                    aCount, bCount, cCount, dCount, eCount, fCount);
    }
    else { // no grades were entered, so output appropriate message
        cout << "No grades were entered\n";
    }
}
