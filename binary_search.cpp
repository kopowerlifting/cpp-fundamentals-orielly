// binary_search.cpp
// Sorting and searching arrays.
#include <array>
#include <algorithm>
#include <format>
#include <iostream>
#include <string>

int main() {
    using namespace std::string_literals; // enables string object literals

    // colours is ingerred to be an array<string, 7>
    std::array colors{"red"s, "orange"s, "yellow"s,
        "green"s, "blue"s, "indigo"s, "violet"s};

    // output original array
    std::cout << "Unsorted colors array:\n   ";
    for (const std::string& color : colors) {
        std::cout << std::format("{} ", color);
    }

    // sort contents of colors
    std::sort(std::begin(colors), std::end(colors));

    // output sorted array
    std::cout << "\nSorted colors array:\n   ";
    for(const std::string& color : colors) {
        std::cout << std::format("{} ", color);
    }

    // search for "indigo" in colors
    bool found{std::binary_search(
        std::begin(colors), std::end(colors), "indigo")};
    std::cout << std::format("\n\n\"indigo\" {} found in colors array\n",
    found ? "was" : "was not");

    // search for "cyan" in colors
    found = std::binary_search(
        std::begin(colors), std::end(colors), "cyan");
    std::cout << std::format("\"cyan\" {} found in colors array\n",
    found ? "was" : "was not");
}