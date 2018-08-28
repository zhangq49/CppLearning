#include <mutex>
#include <iostream>

std::recursive_mutex m;

void g() {
	std::unique_lock<std::recursive_mutex> lock(m);
	std::cout << "lock acquired in g." << std::endl;
}

void f() {
	std::unique_lock<std::recursive_mutex> lock(m);
	std::cout << "lock acquired in f." << std::endl;
	g();
}

int main() {
	f();

	return 0;
}