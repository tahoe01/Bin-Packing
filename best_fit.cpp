#include "project2.h"
#include "item.h"
#include <algorithm>
#include <functional>
#include <cmath>
#include <iostream>

using namespace std;

// Implementation of best fit algorithm
void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int bin = 0;
    double cap = 1.0;

    for (int i = 0; i < n; ++i) {
        int j;
        int min_left_bin = -1;
        double min_left = cap + 1.0;

        for (j = 0; j < bin; ++j) {
            if ((items[i] < free_space[j] || fabs(items[i] - free_space[j]) < __DBL_EPSILON__) && free_space[j] - items[i] < min_left) {
                min_left_bin = j;
                min_left = free_space[j] - items[i];
            }
        }

        if (min_left_bin == -1) { // Doesn't fit in any bin => start a new bin
            free_space.push_back(cap - items[i]);
            assignment[i] = bin;
            ++bin;
        } else { // Find a bin where it fits tightest
            free_space[min_left_bin] -= items[i];
            assignment[i] = min_left_bin;
        }
    }

    for (int k = 0; k  < free_space.size(); ++k) {
        if (fabs(free_space[k]) < __DBL_EPSILON__) {
            free_space[k] = 0.0;
        }
    }
}

void best_fit_d(const vector<item>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int bin = 0;
    double cap = 1.0;

    for (int i = 0; i < n; ++i) {
        // cout << items[i].val << endl;
        int j;
        int min_left_bin = -1;
        double min_left = cap + 1.0;

        for (j = 0; j < bin; ++j) {
            if ((items[i].val < free_space[j] || fabs(items[i].val - free_space[j]) < __DBL_EPSILON__) && free_space[j] - items[i].val < min_left) {
                min_left_bin = j;
                min_left = free_space[j] - items[i].val;
            }
        }

        if (min_left_bin == -1) { // Doesn't fit in any bin => start a new bin
            free_space.push_back(cap - items[i].val);
            assignment[items[i].id] = bin;
            ++bin;
        } else { // Find a bin where it fits tightest
            free_space[min_left_bin] -= items[i].val;
            assignment[items[i].id] = min_left_bin;
        }
    }

    for (int k = 0; k  < free_space.size(); ++k) {
        if (fabs(free_space[k]) < __DBL_EPSILON__) {
            free_space[k] = 0.0;
        }
    }
}


// Implementation of best fit decreasing algorithm
void best_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    vector<item> items_d;
    int n = items.size();
    for (int i = 0; i < n; ++i) {
        item itm = {items[i], i};
        items_d.push_back(itm);
    }

    sort(items_d.begin(), items_d.end(), comp);
    best_fit_d(items_d, assignment, free_space);
}