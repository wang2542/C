#include <iostream>

using namespace std;


void f4_8() {
	unsigned long bits = 1;
	cout << bits << endl;
	// 00000000 00000001 
	cout << (bits << 8) << endl;
	// 00000001 00000000
	cout << (bits << 16) << endl;
	// 00000001 00000000 00000000
	cout << (bits >> 1) << endl;
	// 00000000 00000000 00000000
	cout << (~bits) << endl;
	// 00000000 00000000 00000001
	unsigned int bits2 = 1;
	cout << (~bits2) << endl;
	signed int bits3 = 1;
	signed int bits4 = 3;
	cout << (~bits3) << endl;
	cout << (bits3 & bits4) << endl;
	// 0001
	// 0011
	// 0001  AND
	cout << (bits3 | bits4) << endl;
	// 0001
	// 0011
	// 0011  OR
	cout << (bits3 ^ bits4) << endl;
	// 0001
	// 0011
	// 0010  XOR
}

void f4_8_2() {
	unsigned long quiz1 = 0;
	quiz1 |= 1UL << 27;
	// 学生通过了测验
	// 等价于 => quiz1 = quiz1 | 1UL << 27;
	cout << quiz1 << endl;

	quiz1 &= ~(1UL << 27);
	// 学生没有通过测验
	cout << quiz1 << endl;

	bool status = quiz1 & (1UL << 27);
	// 检查学生是否通过测验
	cout << status << endl;
	

}

int main() {
	f4_8();
	cout << "=======4_8 END========" << endl;
	f4_8_2();
	return 0;
}
