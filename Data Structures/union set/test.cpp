#include "union_set.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	UnionSet friends_set(n);
	int value1, value2;
	for (int i = 0; i < m; i++) {
		cin >> value1 >> value2;
		friends_set.MergeSets(value1, value2);
	}

	cout << friends_set.GetNumOfSets() << endl;

	return 0;
}