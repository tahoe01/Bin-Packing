#include "project2.h"
#include <cmath>
#include <iostream>

using namespace std;

// Implementation of next_fit algorithm
void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int bin = 0;
    double cap = 1.0;
    double fre = cap;

    for (int i = 0; i < n; ++i) {
        if (items[i] < fre || fabs(items[i] - fre) < __DBL_EPSILON__) {
            assignment[i] = bin;
            fre -= items[i];
        } else {
            ++bin;
            assignment[i] = bin;
            free_space.push_back(fabs(fre) < __DBL_EPSILON__ ? 0.0 : fre);
            fre = cap - items[i];
        }
    }
    if (fabs(fre - cap) >= __DBL_EPSILON__) { // NOT_EQUAL
        free_space.push_back(fabs(fre) < __DBL_EPSILON__ ? 0.0 : fre);
    }
}
