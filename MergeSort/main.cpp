/**
 * main function for the merge sort
 */
#include "merge_sort.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[])
{
	if(argc == 1){
		std::cout<<"Use ./mergesort --help for usage"<<std::endl;
		return 0;
	}
	if(strlen(argv[1]) == 6 && strncmp(argv[1], "--help", 6) == 0){
		std::cout<<"Usage:"<<std::endl;
		std::cout<<"	./mergesort --console (number 0) (number 1) (number2)...(number n) will read number from stdin and output result to stdout"<<std::endl;
		std::cout<<"	./mergesort --file (file 0) (file 1) will read numbers from file 0 and print the sort result to file 1"<<std::endl;
	}

	else if(strlen(argv[1]) == 9 && strncmp(argv[1], "--console", 9) == 0){
		std::vector<int> data;
		for(size_t i = 2; argv[i]; i++){
			data.push_back(atoi(argv[i]));
		}
		std::vector<int> sorted = merge_sort(data);

		for(size_t i = 0; i < sorted.size(); i++){
			std::cout<<sorted[i]<<" ";
		}
		std::cout<<std::endl;
		return 0;
	}

	else if(strlen(argv[1]) == 6 && strncmp(argv[1], "--file", 6) == 0){
		//std::cout<<"file"<<std::endl;
		std::ifstream read_file(argv[2]);
		std::ofstream write_file(argv[3]);

		std::string data((std::istreambuf_iterator<char>(read_file)), std::istreambuf_iterator<char>());
		//std::cout<<data<<std::endl;
		//write_file << data;

		//need to improve here
		std::stringstream ss(data);
		std::istream_iterator<std::string> begin(ss);
		std::istream_iterator<std::string> end;
		std::vector<std::string> string_array(begin, end);
		std::vector<int> int_array;
		for(size_t i = 0; i < string_array.size(); i++){
			int_array.push_back(atoi(string_array[i].c_str()));
		}
		std::vector<int> sorted = merge_sort(int_array);
		for(size_t i = 0; i < int_array.size(); i++){
			write_file<<int_array[i]<<" ";
		}
		write_file<<std::endl;
	}

	else{
		std::cout<<"Use ./mergesort --help for usage"<<std::endl;
		return 0;
	}

	return 0;
}
