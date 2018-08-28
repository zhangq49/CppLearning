#ifndef _UNION_SET_HPP
#define _UNION_SET_HPP

#include <vector>

class UnionSet {
public:
	UnionSet() = delete;
	UnionSet(int size);
	~UnionSet() {}

	int GetSetRoot(int value);
	void MergeSets(int value1, int value2);
	int GetNumOfSets();

private:
	std::vector<int> data_;// cannot use std::vector<int> v(10);                                                                                                                                                                
};

#endif