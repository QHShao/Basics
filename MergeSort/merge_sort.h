/**
 * Header file for merge sort
 */
#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_
#include <vector>

std::vector<int> merge(std::vector<int> & array, const std::vector<int> left_half, const std::vector<int> right_half);
std::vector<int> merge_sort(std::vector<int> & array);

#endif