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

uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub);
}

template<typename T>
void shuffle_vector(vector<T>& nums)
{
    int size = nums.size();
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();
    for (int k = size-1; k > 0; --k) {
        uniform_int_distribution<int> ui = get_uniform_int_generator(0, k);
        int j = ui(mt);
        swap_element<T>(nums[k], nums[j]);
    }
}

# endif // RANDOM_GENERATION_SAMPLE_CPP
