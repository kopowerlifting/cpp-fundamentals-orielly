// spans_onc.cpp
// Objects natural case study spans
// creating views into containers.
#include <array>
#include <format>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

// items paramater is treated as a const int* so we also need the size
// to know how to iteratte over items with count-controlled iteration
void displayArray(const int items[], size_t size) {
    for (size_t i{0}; i < size; ++i) {
        std::cout << std::format("{} ", items[i]);
    }
}

// span parameter contains both the location of the first item
// and the number of elemetns, so we can iterate using range-based for loop
void displaySpan(std::span<const int> items) { // spans are iterable
    for (const auto& item : items) {
        std::cout << std::format("{} ", item);
    }
}

// spans can be used to modify elements in the original data structure
void times2(std::span<int> items) {
    for (int& item : items) {
        item *= 2;
    }
}

int main() {
    int values1[]{1, 2, 3, 4, 5};
    std::array values2{6, 7, 8, 9, 10};
    std::vector values3{11, 12, 13, 14, 15};

    // must specify size because the compiler treats displayArray's items
    // paramater as a pointer to the first element of the argument
    std::cout << "values1 via displayArray: ";
    displayArray(values1, 5);

    // compiler knows value1's size and automatically creates a span
    // representing &values1[0] and the array's length
    std::cout << "\nvalues1 via displaySpan: ";
    displaySpan(values1);

    // compiler also can create spans from std::arrays and std::vectors
    std::cout << "\nvalues2 via displaySpan: ";
    displaySpan(values2);
    std::cout << "\nvalues3 via displaySpan: ";
    displaySpan(values3);

    // changin the values in the original data structure using a span
    std::cout << "\n\nvalues1 before times2: ";
    displaySpan(values1);
    times2(values1);
    std::cout << "\nvalues1 after times2: ";
    displaySpan(values1);

    // spans have various array-and-vector-like capabilitys
    std::span mySpan{values1}; // span<int>
    std::cout << "\n\nmySpan's first element: " << mySpan.front()
        << "\nmySpan's last element: " << mySpan.back()
        << "\nmySpan's size: " << mySpan.size()
        << "\nmySpan is empty? " << std::boolalpha << mySpan.empty() << '\n'; 

    // spans can be used with standard library algorithms
    std::cout << "\nmySpan's sum: "
        << std::accumulate(mySpan.begin(), mySpan.end(), 0) << '\n';

    // spans can be used to create subviews of a container
    std::cout << "\nmySpan's subspan from index 1 to 3: ";
    displaySpan(mySpan.subspan(1, 3));
    std::cout << "\nmySpan's subspan from index 2 to the end: ";
    displaySpan(mySpan.subspan(2));
    std::cout << "\nmySpan's middle subspan: ";
    displaySpan(mySpan.subspan(mySpan.size() / 2, mySpan.size() / 2));

    // changing subspan values
    times2(mySpan.subspan(1, 3));
    std::cout << "\n\nmySpan after times2 on subspan from index 1 to 3: ";
    displaySpan(mySpan);

    // accessing like an array
    std::cout << "\nmySpan[0]: " << mySpan[0]
        << "\nmySpan[1]: " << mySpan[1]
        << "\nmySpan[2]: " << mySpan[2]
        << "\nmySpan[3]: " << mySpan[3]
        << "\nmySpan[4]: " << mySpan[4] << '\n';
}