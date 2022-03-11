#include <iostream>

void f2_4() {
	// 定义一种变量，且他的值不能被改变
	const int bufSize = 512;

	// 利用一个对象初始化另外一个对象
	int i = 42;
	const int ci = i;
	std :: cout << "ci value is: " << ci << std :: endl;
	std :: cout << "===========2_4=============" << std :: endl;
}

void f2_4_1() {
	const int ci = 1024;
	const int &r1 = ci; 	// 引用其对应的对象都是常量
	// int &r2 = ci;	// 不能让一个非常量引用指向一个常量对象
	std :: cout << "r1 value is: " << r1 << std :: endl;
	std :: cout << "ci address is: " << &ci << std :: endl;
	std :: cout << "r1 address is: " << &r1 << std :: endl;
	std :: cout << "===========2_4_1=============" << std :: endl;
}

void f2_4_2() {
	int errNumb = 0;
	int *const curErr = &errNumb;	// currErr 将一直指向errNumb

	std :: cout << "errNumb address is: " << &errNumb << std :: endl;
	std :: cout << "curErr value is: " << curErr << std :: endl;
	std :: cout << "*curErr value is: " << *curErr << std :: endl;
	std :: cout << "curErr address is: " << &curErr << std :: endl;
	errNumb = 1;
	std :: cout << "Set errNumb = 1;" << std :: endl;
	std :: cout << "curErr value is: " << curErr << std :: endl;
	std :: cout << "*curErr value is: " << *curErr << std :: endl;
	std :: cout << "curErr address is: " << &curErr << std :: endl;


	const double pi = 3.14159;
	const double *const pip = &pi;	// pip是一个指向常量对象的常量指针

	std :: cout << "pi address is: " << &pi << std :: endl;
	std :: cout << "pip value is: " << pip << std :: endl;
	std :: cout << "*pip value is: " << *pip << std :: endl;
	std :: cout << "pip address is: " << &pip << std :: endl;
	std :: cout << "===========2_4_2=============" << std :: endl;
}

int main() {
	f2_4();
	f2_4_1();
	f2_4_2();
	return 0;

}
