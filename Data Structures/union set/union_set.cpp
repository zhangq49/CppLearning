#include "union_set.h"

UnionSet::UnionSet(int size) : data_(size) {
	for (int i = 0; i < data_.size(); i++) {
		data_[i] = i;
	}
}


int UnionSet::GetSetRoot(int value) {
	if (value == data_[value]) {
		return value;
	}

	data_[value] = GetSetRoot(data_[value]);
	return data_[value];
}

void UnionSet::MergeSets(int value1, int value2) {
	int root1 = GetSetRoot(value1);
	int root2 = GetSetRoot(value2);
	if (root1 != root2) {
		data_[root2] = root1;
	}
}

int UnionSet::GetNumOfSets() {
	int num = 0;
	for (int i = 0; i < data_.size(); i++) {
		if (data_[i] == i)
			num++;
	}
	return num;
}
