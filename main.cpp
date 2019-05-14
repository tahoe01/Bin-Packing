#include <iostream>
#include <fstream>
#include <algorithm>
#include <float.h>
#include <functional>

#include "next_fit.cpp"
#include "first_fit.cpp"
#include "best_fit.cpp"
#include "random_generation_sample.cpp"

using namespace std;

struct waste {
    int n;
    double waste;
};

// run and time sort for vector with n elements. return vector of timings with sizes and seconds
waste estimate_waste(int n, int reps, function<void(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)> bin_packing) {
    double total_waste = 0.0;
    vector<int> rvec;

    for(int i = 0; i < reps; i++) // For each input size, do "reps" times runs.
    {
        vector<double> items; // N items in the vector are floating point numbers between 0 and 1 generated uniformly at random.
        double min_waste= DBL_MAX;
        for (int j = 0; j < 3; j++) { // For each input vector, do 3 runs and take the smallest waste.
            vector<int> assignment(items.size(), 0);
            vector<double> free_space;
            bin_packing(items, assignment, free_space);

            double curr_waste = free_space.size() - accumulate(items.begin(), items.end(), 0);
            if (curr_waste < min_waste) {
                min_waste = curr_waste;
            }
        }  
        total_waste += min_waste;
    }

    waste w;
    w.n = n;
    w.waste = (float)total_waste/reps;  // Average minimum running time of each size
    
    return w;
}

// create/truncate a file with chosen filename. insert csv header "funcname,n,waste"
void create_empty_waste_file(string filename) {
    ofstream f;
    f.open(filename, ios::trunc);
    f << "funcname,n,waste\n";
    f.close();
}

// append timings data in csv format to a file with no header. (header should be created first)
void add_waste_to_file(string funcname, waste t, string filename) {
    ofstream f;
    f.open(filename, ios::app);
    f << funcname << "," << t.n << "," << t.waste << "\n";
    f.close();
}

// Implementation of main function
int main() {
    create_empty_waste_file("next_fit.csv");
    create_empty_waste_file("first_fit.csv");
    create_empty_waste_file("first_fit_decreasing.csv");
    create_empty_waste_file("best_fit.csv");
    create_empty_waste_file("best_fit_decreasing.csv");

    waste w;

    for(int n = 10; n <= 10000; n *= 10)
    {
        w = estimate_waste(n, 3, next_fit);
        add_waste_to_file("next_fit", w, "next_fit.csv");

        // w = estimate_waste(n, 3, first_fit);
        // add_waste_to_file("first_fit", w, "first_fit.csv");

        // w = estimate_waste(n, 3, first_fit_decreasing);
        // add_waste_to_file("first_fit", w, "first_fit_decreasing.csv");

        // w = estimate_waste(n, 3, best_fit);
        // add_waste_to_file("best_fit", w, "best_fit.csv");

        // w = estimate_waste(n, 3, best_fit_decreasing);
        // add_waste_to_file("best_fit_decreasing", w, "best_fit_decreasing.csv");
    }

    return 0;
}