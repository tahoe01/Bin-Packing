#include <vector>

// implement in next_fit.cpp
void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);

//implement in first_fit.cpp
void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);
void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);

// implement in best_fit.cpp
void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);
void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space);

/* 
 * for all functions
 * params:
 *      items: the items to assign to bins
 *      assignment: the assignment of the ith item to the jth bin for all i items. 
 *                  assume assignment.size() == items.size().
 *                  you should not add any new elements to this vector.
 *                  you must modify this vector's elements to indicate the assignment.
 *      free_space: the amount of space left in the jth bin for all j bins created in the algorithm.
 *                  you should add one element for each bin that the algorithm creates.
 *                  when the function returns, this should indicate the final free space available in each bin.
 *
 * example usage:
 *      std::vector<double> items; 
 *      ...populate items...
 *      std::vector<int> assignment(items.size(), 0); // same size as items, all values are 0
 *      std::vector<double> free_space; // empty double vector
 *      next_fit(items, assignment, free_space); 
 *      // at this point, 
 *      //      assignment should hold the assignment next_fit makes,
 *      //      free_space should have as many elements as bins created by next_fit,
 *      //              with the final free space available in the corresponding bins
 */
