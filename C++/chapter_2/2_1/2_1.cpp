#include <iostream>
#include <string>

int main() { 				// 最小尺寸
	bool flag = true;		// 未定义 
	char a = 'a';			// 8  位
	wchar_t wa = L'a';		// 16 位
	char16_t ca16 = u'王';		// 16 位
	char32_t ca32 = u'王';		// 32 位
	short num_s = 1024;		// 16 位
	int num_i = 1024;		// 16 位
	long num_l = 1024;		// 32 位
	long long num_ll = 1024;	// 64 位
	float num_f = 1024;		// 6  位有效数字
	double num_d = 1024;		// 10 位有效数字
	long double num_ld = 1024;	// 10 位有效数字


	std :: cout << "Bool value is: "  << flag << ", and the size is :" << sizeof(flag) << std :: endl;
	std :: cout << "char value is: "  << a	  << ", and the size is :" << sizeof(a)    << std :: endl;
	std :: cout << "wchar value is: " << wa	  << ", and the size is :" << sizeof(wa)   << std :: endl;
	std :: cout <<"char16_t value is:"<< ca16 << ", and the size is :" << sizeof(ca16) << std :: endl;
	std :: cout <<"char32_t value is:"<< ca32 << ", and the size is :" << sizeof(ca32) << std :: endl;

	std :: cout << "short value is: "     	<< num_s << ", and the size is :" << sizeof(num_s) << std :: endl;
	std :: cout << "int value is: "  	<< num_i << ", and the size is :" << sizeof(num_i) << std :: endl;
	std :: cout << "long value is: "   	<< num_l << ", and the size is :" << sizeof(num_l) << std :: endl;
	std :: cout << "long long value is: "  	<< num_ll<< ", and the size is :" << sizeof(num_ll)<< std :: endl;
	std :: cout << "float value is: "  	<< num_f << ", and the size is :" << sizeof(num_f) << std :: endl;
	std :: cout << "double value is: "  	<< num_d << ", and the size is :" << sizeof(num_d) << std :: endl;
	std :: cout << "long double value is: " << num_ld<< ", and the size is :" << sizeof(num_ld)<< std :: endl;
}
