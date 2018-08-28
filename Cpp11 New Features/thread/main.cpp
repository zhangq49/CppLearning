#include <iostream>
#include <thread>

using namespace std;

void foo() {
	cout << "foo" << endl;
}

int main() {
	thread t(foo);
	t.join();
	
	return 0;
}