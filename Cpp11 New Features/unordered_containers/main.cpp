#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<int, string> u = {
        {1, "1"},
        {3, "3"},
        {2, "2"}
    };

    map<int, string> m = {
    	{1, "1"},
    	{3, "3"},
    	{2, "2"},
    };

    cout << "unordered_map:" << endl;
    for (const auto& i : u)
    	cout << "Key:[" << i.first << "] Value:[" << i.second << "]\n";

    cout << "map:" << endl;
    for (const auto& i : m)
    	cout << "Key:[" << i.first << "] Value:[" << i.second << "]\n";

    std::cout << std::endl;

    return 0;
}