/**
 * implementation of merge sort
 */
#include "merge_sort.h"
#include <iostream>

std::vector<int> merge(std::vector<int> & array, const std::vector<int> left_half, const std::vector<int> right_half)
{
	std::vector<int> merged_arr;
	size_t left_half_index = 0, right_half_index = 0;

	while(left_half_index < left_half.size() && right_half_index < right_half.size()){
		if(left_half[left_half_index] <= right_half[right_half_index]){
			merged_arr.push_back(left_half[left_half_index]);
			left_half_index++;
		}
		else{
			merged_arr.push_back(right_half[right_half_index]);
			right_half_index++;
		}
	}

	while(left_half_index < left_half.size()){
		merged_arr.push_back(left_half[left_half_index]);
		left_half_index++;
	}

	while(right_half_index < right_half.size()){
		merged_arr.push_back(right_half[right_half_index]);
		right_half_index++;
	}
	array = merged_arr;
	return array;
}

std::vector<int> merge_sort(std::vector<int> & array)
{
	if(array.size() == 0){
		std::cout<<"No data for sorting!"<<std::endl;
		return std::vector<int>();
	}
	if(array.size() == 1){
		return array;
	}
	std::vector<int>::iterator midpoint = array.begin() + (array.size() / 2);
	std::vector<int> left_half(array.begin(), midpoint);
	std::vector<int> right_half(midpoint, array.end());

	left_half = merge_sort(left_half);
	right_half = merge_sort(right_half);

	return merge(array, left_half, right_half);
}