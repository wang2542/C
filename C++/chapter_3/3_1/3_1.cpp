#include <iostream>

// 编译器从左侧名字所示的作用域寻找右侧那个名字
// using namespace :: name;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;

void f3_1() {
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2
	     << " is " << v1 + v2 << endl;

}

void f3_2_1() {
	string s1;		// 默认初始化
	string s2 = s1;		// s2是s1的副本
	string s3 = "hiya";	// s3是该字符串字面值的副本
	string s4(10, 'c'); 	// s4是是个c

	cout << "s1 is : " << s1 << endl;
	cout << "s2 is : " << s2 << endl;
	cout << "s3 is : " << s3 << endl;
	cout << "s4 is : " << s4 << endl;
	
	// copy initialization -> 把等号右侧初始值拷贝到新创建的对象中，例如s3 -> 拷贝初始化
	// direct initialization -> 不使用等号 -> 直接初始化
}

void f3_2_2() {
	string s1 = "Hello";
	string s2 = "World";
	string input;

	cout << "Check getline function: " << endl;
	getline(cin , input);
	cout << "Output: " << input << endl;
	cout << "Check s1.empty() is: " << s1.empty() << endl;
	cout << "Check s1.size() is: " << s1.size() << endl;
	cout << "Check s1[3] is: " << s1[3] << endl;
	cout << "Check s1 + s2 is: " << s1+s2 << endl;

}

void f3_2_3() {
	// 如何处理string中每个字符
	char test = 'a';
	cout << (bool)isalnum(test) << endl;	// 当test是字母或数字	为真
	cout << (bool)isalpha(test) << endl;	// 当test是字母时	为真
	cout << (bool)iscntrl(test) << endl;	// 当test是控制字符	为真
	cout << (bool)isdigit(test) << endl;	// 当test是数字时	为真
	cout << (bool)isgraph(test) << endl;	// 当test不是空格但可以打印
	cout << (bool)islower(test) << endl;	// 当test是小写字母	为真
	cout << (bool)isprint(test) << endl;	// 当test是可以打印字符	为真
	cout << (bool)ispunct(test) << endl;	// 当test是标点符号	为真
	cout << (bool)isspace(test) << endl; 	// 当test是空白时	为真
	cout << (bool)isupper(test) << endl; 	// 当test是大写字母时	为真

	cout << "cout how many punctuation in the \"Hello World!!!\"" << endl;
	string line("Hello World!!!");
	decltype(line.size()) punct_cnt = 0;
	for ( auto c : line) {
		if (ispunct(c))
			++punct_cnt;
	}
	cout << punct_cnt << " punctuation characters in " << line << endl;

}

int main() {
	f3_1();
	cout << "========f3_1 END==========" << endl;
	f3_2_1();
	cout << "========f3_2_1 END==========" << endl;
	f3_2_2();
	cout << "========f3_2_2 END==========" << endl;
	f3_2_3();

}
