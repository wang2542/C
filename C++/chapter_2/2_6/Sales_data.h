#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
	std :: string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

#endif

// 预处理变量有两种状态：已定义 和 未定义
// #define指令把一个名字设定为预处理变量，另外两个指令则分别检查某个指定的预处理变量是否已经定义：
// #ifdef 当且仅当变量已定义时为真，#ifndef 当且仅当变量未定义时为真
// 一旦检查结果为真，则执行后续直到遇到#endif 指令为止

