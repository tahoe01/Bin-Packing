#include "project2.h"
#include "item.h"
#include <algorithm>
#include <functional>
#include <cmath>
#include <iostream>

using namespace std;

// Implementation of first fit algorithm
void first_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int bin = 0;
    double cap = 1.0;

    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0 ; j < bin; ++j) {
            if (items[i] < free_space[j] || fabs(items[i] - free_space[j]) < __DBL_EPSILON__) {
                free_space[j] -= items[i];
                assignment[i] = j;
                break;
            }
        }
        if (j == bin) { 
            free_space.push_back(cap - items[i]);
            assignment[i] = bin;
            ++bin;
        }
    }

    for (int k = 0; k  < free_space.size(); ++k) {
        if (fabs(free_space[k]) < __DBL_EPSILON__) {
            free_space[k] = 0.0;
        }
    }
}

// Implementation of first fit algorithm
void first_fit_d(const vector<item>& items, vector<int>& assignment, vector<double>& free_space) {
    int n = items.size();
    int bin = 0;
    double cap = 1.0;

    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0 ; j < bin; ++j) {
            if (items[i].val < free_space[j] || fabs(items[i].val - free_space[j]) < __DBL_EPSILON__) {
                free_space[j] -= items[i].val;
                assignment[items[i].id] = j;
                break;
            }
        }
        if (j == bin) { 
            free_space.push_back(cap - items[i].val);
            assignment[items[i].id] = bin;
            ++bin;
        }
    }

    for (int k = 0; k  < free_space.size(); ++k) {
        if (fabs(free_space[k]) < __DBL_EPSILON__) {
            free_space[k] = 0.0;
        }
    }
}


// Implementation of first fit decreasing algorithm
void first_fit_decreasing(const vector<double>& items, vector<int>& assignment, vector<double>& free_space) {
    vector<item> items_d;
    int n = items.size();
    for (int i = 0; i < n; ++i) {
        item itm = {items[i], i};
        items_d.push_back(itm);
    }

    sort(items_d.begin(), items_d.end(), comp);
    first_fit_d(items_d, assignment, free_space);
}