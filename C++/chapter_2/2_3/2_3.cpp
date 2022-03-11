#include <iostream>

void f2_3_1() {
	int ival = 1024;
	int &refVal = ival;
	std :: cout << "set ival : " << ival << std :: endl;
	std :: cout << "refVal refer to ival, refVal is: "<< refVal << std :: endl;

	refVal = 2;
	std :: cout << "set refVal to 2, ival is : " << ival << std :: endl;
	std :: cout << "refVal is : " << refVal << std :: endl;

	int ii = refVal;
	std :: cout << "set ii = refVal, ii is: " << ii << std :: endl;

	int &refVal3 = refVal;
	std :: cout << "set &refVal3 = refVal, refVal3 is: " << refVal3 << std :: endl;
	int i = refVal;
	std :: cout << "set i = refVal, i is: " << i << std :: endl;
	std :: cout << "-----------------2_3_1 Finished----------------------" << std :: endl;
}

void f2_3_2() {
	int *ip1, *ip2;		// ip1 和 ip2 都是指向int型对象的指针
	double dp, *dp2;	// dp2 是指向double型的指针，dp是double型对象

	int ival = 42;
	int *p = &ival;		// p 存放变量ival的地址，或者说p是指向变量ival的指针

	std :: cout << "ival value is:<" << ival << ">" << std::endl;
	std :: cout << "ival address is:<" << &ival << ">" << std::endl;
	std :: cout << "pointer p address is : <"<< &p << ">, and it store address (ival) is <" << p << ">" <<std :: endl;

	double dval = 1024;
	double *pd = &dval;	// 初始值是double型对象的地址
	double *pd2 = pd;	// 初始值是指向double对象的指针
	std :: cout << "Set dval = 1024, and the dval address is:<" << &dval << ">" << std::endl;
	std :: cout << "pointer pd address is : <"<< &pd << ">, and it store address (dval) is <" << pd << ">" <<std :: endl;
	std :: cout << "pointer pd2 address is : <"<< &pd2 << ">, and it store address (pd) is <" << pd2 << ">" <<std :: endl;
	std :: cout << "pointer pd value is : " <<  *pd  << ", pointer pd2 value is : " << *pd2 << std :: endl;

	std :: cout << "-----------------2_3_2 Finished----------------------" << std :: endl;

}

void f2_3_3() {
	int ival = 1024;
	int *pi = &ival;	// pi 指向一个int型的数
	int **ppi = &pi;	// ppi指向一个int型的指针

	std :: cout << "ival value is:<" << ival << ">" << std::endl;
	std :: cout << "ival address is:<" << &ival << ">" << std::endl;
	std :: cout << "pointer pi address is : <"<< &pi << ">, and it store address (ival) is <" << pi << ">, the *pi is:" << *pi <<std :: endl;
	std :: cout << "pointer ppi address is : <"<< &ppi << ">, and it store address (pi) is <" << ppi << ">, the * ppi is:" << **ppi <<std :: endl;


}


int main() {
	f2_3_1();
	f2_3_2();
	f2_3_3();
	return 0;
}
