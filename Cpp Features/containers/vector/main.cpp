#include<vector>
#include<string>

using namespace std;

int main() {
	vector<int> v1;
	vector<int> v2(v1);
	vector<int> v3(v1.begin(), v1.end());
	vector<int> v4(10);
	vector<int> v5(10, 4);
	vector<string> v6(10, "null");
	vector<string> v7(10, "hello");

	v1.push_back(100);
	int size = v1.size();
	bool isEmpty = v1.empty();
	cout << v1[0] << endl;
	v1.insert(v1.end(), 5, 3);
	v1.pop_back();
	v1.erase(v1.begin(), v1.end());
	cout << (v1 == v2 ? true : false) << endl;
	vector<int>::iterator iter = v1.begin();
	vector<int>::const_iterator iter = v1.end();
	v1.clear();

	return 0;
}