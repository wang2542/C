#include <iostream>
#include <vector>

using std :: cout;
using std :: cin;
using std :: endl;
using std :: string;
using std :: vector;

void f3_3_1() {
	vector<string> 	v1{"a", "an", "the"};
	vector<int>	ivec(10, -1);		// 10个元素，10个-1
	vector<int>	ivec2{10, -1};		// 2个元素，10和-1
}

void f3_3_2() {
	vector<int> v2;
	for (int i = 0; i != 100; ++i)
		v2.push_back(i);
}

void f3_3_3() {
	vector<int> v{1,2,3,4,5,6,7,8,9};
	for (auto &i : v)
		i *= i;
	for (auto i : v)
		cout << i << " ";
	cout << endl;
}

int main() {
	f3_3_3();
	return 0;
}
