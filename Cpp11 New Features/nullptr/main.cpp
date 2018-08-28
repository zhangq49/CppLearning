#include <iostream>

using namespace std;

const class mynullptr_t {
public:
	template<class T>
	operator T*() const {
		cout << "T*() is called!\n" << endl;
		return 0;
	}

	template<class C, class T>
	operator T C::*() const {
		cout << "T C::*() is called!\n" << endl;
		return 0;
	}

private:
	void operator&() const;
} mynullptr = {};

class A {
public:
	int* a;
	int* b;
	int (*func)(int);
};

int main() {
	int* p = mynullptr;
	A a;
	a.a = mynullptr;
	a.b = mynullptr;
	a.func = mynullptr;

	cout << p << endl;
	cout << a.a << endl;
	cout << a.b << endl;
	cout << a.func << endl;

	return 0;
} 