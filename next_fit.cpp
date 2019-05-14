#include "project2.h"
#include <iostream>

using namespace std;

// Implementation of next_fit algorithm
void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int bin = 0;
    double cap = 1.0;
    double fre = cap;

    for (int i = 0; i < n; ++i) {
        if (items[i] <= fre) {
            assignment[i] = bin;
            fre -= items[i];
        } else {
            ++bin;
            assignment[i] = bin;
            free_space.push_back(fre);
            fre = cap - items[i];
        }
    }
    if (fre != cap) {
        free_space.push_back(fre);
    }
    // cout << "Number of bins used: " << bin + 1 << endl;
    // cout << "Assignment: " << endl;
    // for (int j = 0; j < n; ++j) {
    //     cout << assignment[j] << endl;
    // }
    // cout << "Free space of each bin: " << endl;
    // for (int j = 0; j < bin + 1; ++j) {
    //     cout << free_space[j] << endl;
    // }
}

// int main() {
//     vector<double> items{0.7, 0.5, 0.3, 0.1, 0.1, 0.6, 0.4, 0.9}; 
//     vector<int> assignment(items.size(), 0); // same size as items, all values are 0
//     vector<double> free_space; // empty double vector
//     next_fit(items, assignment, free_space); 
//     // at this point, 
//     //      assignment should hold the assignment next_fit makes,
//     //      free_space should have as many elements as bins created by next_fit,
//     //              with the final free space available in the corresponding bins
// }
