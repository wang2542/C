#include <iostream>
#include <vector>

using std :: vector;
using std :: string;
using std :: cout;
using std :: endl;

void f3_4_1() {
	string s("some thing");
	if (s.begin() != s.end() ) {
		auto it = s.begin();
		*it = toupper(*it);
		cout << s << endl;
	}

	// 将迭代器移动到另一个元素
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
		*it = toupper(*it);

	cout << s << endl;
}

void f3_4_2() {
	// text 必须是排序过的
	// beg和end表示我们得搜索范围
	vector<string> text{"a","b","c","d","e","f","g","h","i","j","k","l"};
	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg) / 2;
	string sought = "h";
	while (mid != end && *mid != sought) {
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
		//cout << "beg is : " << beg << ", end is : " << end << endl;
		cout << "mid change to : " << *mid << endl;
	}
}

int main() {
	f3_4_1();
	f3_4_2();
	return 0;

}
