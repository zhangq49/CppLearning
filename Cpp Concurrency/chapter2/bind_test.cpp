#include <iostream>
#include "bind.h"

void TestFun1(int a, int b, int c)
{
	std::cout << a << b << c << std::endl;
}

void TestBind1()
{
    Bind(&TestFun1,  _1,  _2,  _3)(1, 2, 3);
    Bind(&TestFun1, 4, 5, _1)(6);
    Bind(&TestFun1, _1, 4, 5)(3);
    Bind(&TestFun1, 3, _1,  5)(4);
}

int main() {
	TestBind1();
	return 0;
}