// store_sales_summary.cpp
// A test of all the lessons I have learned in part 1 of the C++ course.
// Copilot suggested a program that summarizes stores sales data.
// The program will use random number generation to simulate sales data for a number of stores over a period of time.
// The program will then calculate and display the total sales within a given time period, the average sales per store, and the store with the highest sales.

#include <iostream>
#include <format>
#include <random>
using namespace std;

struct Store {
    int totalSales{0};
    int bestSalesDay{0};
    int worstSalesDay{0};
    int daysAboveTarget{0};
    int daysBelowTarget{0};
};

// randomly generates store sales for specified days +- 20% of target and returns the sum
Store storeSales(int days, int target);
void performanceSummary(const Store& store, int days, int target);

int main() {    
    int days{0};
    int target{0};
    int sum{0};

    cout << "Enter the sales target and period length in days: ";
    cin >> target >> days;

    cout << format("\nSales target: ${}\nPeriod length: {} days", target, days);

    const Store store = storeSales(days, target);

    cout << format("\n\nTotal sales: ${}", store.totalSales);

    performanceSummary(store, days, target);

    return 0;
}

Store storeSales(int days, int target) {
    const int min{target * 80 / 100};
    const int max{target * 120 / 100};
    Store store;

    static random_device rd; // used to seed the detault_random_enging
    static default_random_engine engine{rd()}; // rd()  produces a seed
    uniform_int_distribution randomSales{min, max};

    cout << format("Target: ${}\n\n", target);
    
    for (int i{1}; i <= days; ++i) {
        int sales{randomSales(engine)};
        if (sales > target) {
            store.daysAboveTarget++;
        }
        if (sales < target) {
            store.daysBelowTarget++;
        }
        if (sales > store.bestSalesDay) {
            store.bestSalesDay = sales;
        }
        if (sales < store.worstSalesDay || store.worstSalesDay == 0) {
            store.worstSalesDay = sales;
        }
        cout << format("Day {}: ${}\n", i, sales);
        store.totalSales += sales;
    }

    return store;
}

void performanceSummary(const Store& store, int days, int target) {
    double average{static_cast<double>(store.totalSales) / days};

    cout << "\n\n PERFORMANCE REPORT\n";
    cout << "-------------------\n";
    cout << format("\nTotal: ${:<10}\n", store.totalSales);
    cout << format("Average: ${:<10.2f}\n", average);
    cout << format("Best Day: ${:<10}\n", store.bestSalesDay);
    cout << format("Worst Day: ${:<10}\n", store.worstSalesDay);
    cout << format("\nDays Above Target: {:<10}\n", store.daysAboveTarget);
    cout << format("Days Below Target: {:<10}\n", store.daysBelowTarget);

    if (store.totalSales > (target * days)) {
        cout << "\nOverall Performance: Above Target\n";
    } else if (store.totalSales == (target * days)) {
        cout << "\nOverall Performance: On Target\n";
    } else {
        cout << "\nOverall Performance: Below Target\n";
    }
}
