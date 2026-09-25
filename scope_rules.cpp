// scope_rules.cpp
// Scoping examples
#include <iostream>
using namespace std;

void useLocal();
void useStaticLocal();
void useGlobal();

int x{1}; //global variable

int main() {
    cout << "global x in main is " << x << "\n";

    const int x{5}; // local variable to main

    cout << "local x in main's outer scope is " << x << "\n";

    { // start new scope
        const int x{7}; // local variable to this inner block
        cout << "local x in main's inner scope is " << x << "\n";
    } // end new scope

    cout << "local x in main's outer scope is " << x << "\n";

    useLocal(); // useLocal has local x
    useStaticLocal(); // useStaticLocal has static local x
    useGlobal(); // useGlobal uses global x
    useLocal(); // useLocal reinitializes local x
    useStaticLocal(); // static local x retains its prior value
    useGlobal(); // global x also retains its prior value

    cout << "local x in main is " << x << "\n";
} // end of main

// useLocal reinitializes local variable x during each call
void useLocal() {
    int x{25}; // initialized each time useLocal is called
    cout << "\nlocal x in useLocal is " << x << " after entering useLocal\n";
    ++x; // modifies this local x
    cout << "local x in useLocal is " << x << " before exiting useLocal\n";
} // end of function useLocal

// useStaticLocal initializes static local variable x only the first time the function is called; value of x is saved between calls to this function
void useStaticLocal() {
    static int x{50}; // initialized once and retains its value between calls
    cout << "\nlocal static x is " << x << " on entering useStaticLocal\n";
    ++x; // modifies this local static x
    cout << "local static x is " << x << " on exiting useStaticLocal\n";
} // end of function useStaticLocal

// useGlobal modifies global variable x during each call
void useGlobal() {
    cout << "\nglobal x is " << x << " on entering useGlobal\n";
    x *= 10; // modifies global x
    cout << "global x is " << x << " on exiting useGlobal\n";
} // end of function useGlobal
