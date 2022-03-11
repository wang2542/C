#include <iostream>
#include "Sales_item.h"

/*
 *  程序将每个ISBN的所有数据合并起来，存入名为total的变量中
 *  我们使用另一个名为trans的变量保存读取的每条销售记录
 *  如果trans和total指向相同ISBN，我们更新total的值
 *  否则我们打印total，并重置为刚读取的数据
 */

// $: ./a.out < input.txt

int main() {
	Sales_item total; // 保存下一条交易记录的变量
	if (std :: cin >> total) {
		Sales_item trans;	// 保存和的变量
		// 如果我们仍在处理相同的书
		while (std :: cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;		// 更新总销售额
			else {
				// 打印前一本书的结果
				std :: cout << total << std :: endl;
				total = trans;		// total 现在表示下一本书的销售额
			}
		}
		std :: cout << total << std :: endl; 	// 打印最后一本书的结果
	} else {
		std :: cerr << "No data?!" << std :: endl;
		return -1; 	// 表示失败
	}

	return 0;
}
