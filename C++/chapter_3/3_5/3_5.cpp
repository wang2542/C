#include <iostream>
#include <string.h>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;

void f3_5_1() {
	int arr[10];
	int *ptrs[10];			// ptrs是含有10个int型指针的数组
	int (*Parray)[10] = &arr; 	// Parray 指向一个含有10个整数的数组
	int (&arrRef)[10] = arr;	// arrRef 引用一个含有10个整数的数组

}

void f3_5_2() {
	// 以10分为一个分段统计数量
	unsigned scores[11] = {};
	unsigned grade;
	while (cin >> grade ) {
		if (grade <= 100)
			++scores[grade/10];
	}

	for (auto i : scores)
		cout << i << " ";
	cout << endl;
		
}

void f3_5_3() {
	string nums[] = {"one", "two", "three"};
	string *p = &nums[0];
	string *p2 = nums;
	cout << *p << " " << *p2 << endl;
	string *beg = begin(nums);		// 指向nums的首元素指针
	string *last = end(nums);		// 指向nums尾元素的下一个位置的指针
	--last; 
	cout << *beg << " " << *last << endl;
}

void f3_5_4() {
	char ca[] = {'C', '+', '+', '\0'};
	cout << strlen(ca) << endl;
	
	// 比较字符串
	string s1 = "A string example";
	string s2 = "A different string";

	cout << (bool)(s1 < s2) << endl;
	// 字符串拼接
	string largeStr = s1 + " " + s2;
	cout << largeStr << endl;
	
	// 如何操作两个数组相加
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";

	char test[100];
	strcpy(test, ca1);
	strcat(test, " ");
	strcat(test, ca2);
	cout << test << endl;
	
}

void f3_5_6() {
	//int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];

	for (size_t i = 0; i != rowCnt; ++i) {
		for (size_t j = 0; j != colCnt; ++j) {
			ia[i][j] = i * colCnt + j;
			cout << ia[i][j] << " ";
		}
		cout << endl;
	}


}

int main() {
	f3_5_1();
	f3_5_2();
	f3_5_3();
	f3_5_4();
	f3_5_6();
	return 0;
}
