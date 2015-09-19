CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -Wall -Wextra -O0 -g -c
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi
EXES = mergesort

all : $(EXES)

mergesort : main.o merge_sort.o
	$(CXX) $(LDFLAGS) main.o merge_sort.o -o mergesort

main.o : main.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) main.cpp

merge_sort.o : merge_sort.cpp merge_sort.h
	$(CXX) $(CXXFLAGS) merge_sort.cpp

clean : 
	rm -rf $(EXES) *.o
