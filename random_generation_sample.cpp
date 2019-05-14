#ifndef RANDOM_GENERATION_SAMPLE_CPP
#define RANDOM_GENERATION_SAMPLE_CPP
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "swap.cpp"

using namespace std;

mt19937 get_mersenne_twister_generator_with_current_time_seed()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    return mt19937(seed);
}

void print_mt_random_numbers(mt19937 mt, int n)
{
    for(int i = 0; i < n; i++)
        cout << mt() << "\n";
}

uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub);
}

void print_mt_bounded_numbers(mt19937 mt, uniform_int_distribution<int> ui, int n)
{
    for(int i = 0; i < n; i++)
        cout << ui(mt) << "\n";
}

int randint(mt19937 mt, int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub)(mt);
}

void shuffle_vector(vector<int>& nums)
{
    int size = nums.size();
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    for (int k = size-1; k > 0; --k) {
        uniform_int_distribution<int> ui = get_uniform_int_generator(0, k);
        int j = ui(mt);
        swap_element(nums[k], nums[j]);
    }
}

void almost_sorted_vector(vector<int>& nums)
{
    int size = nums.size();
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    uniform_int_distribution<int> ui = get_uniform_int_generator(0, size - 1);
    int limit = 2 * log10(size);
    for (int k = 0; k < limit; k++) {
        int i = ui(mt);
        int j = ui(mt);
        swap_element(nums[i], nums[j]);
    }
}

# endif // RANDOM_GENERATION_SAMPLE_CPP
