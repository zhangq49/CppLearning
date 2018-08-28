#include<iostream>

using namespace std;

class A {
public:
	int a;
	A(){ cout << "A" << endl; }
	~A(){ cout << "~A" << endl; }
};

class B : virtual public A {
public:
	int b;
	B(){ cout << "B" << endl; }
	~B(){ cout << "~B" << endl; }
};

class C : virtual public A {
public:
	int c;
	C(){ cout << "C" << endl; }
	~C(){ cout << "~C" << endl; }
};

class D : public B, public C {
public:
	int d;
	D(){ cout << "D" << endl; }
	~D(){ cout << "~D" << endl; }
};

int main() {
	D d;

	cout <<	sizeof(d) << endl;

	return 0;
}