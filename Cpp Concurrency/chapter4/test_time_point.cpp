#include <iostream>
#include <chrono>

using namespace std;


int main(int argc, char const *argv[])
{	
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
		cout << i << endl;
	auto stop = chrono::high_resolution_clock::now();
	cout << "The loop statement took " 
		 << chrono::duration<double, chrono::seconds>(stop - start).cout()
		 << " seconds" << endl;
	
	return 0;
}