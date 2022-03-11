#include <iostream>
#include <string>
#include "Sales_data.h"

// 读入两笔交易： ISBN，销售数量，单价
void read_data(Sales_data &data1, Sales_data &data2) {
	double price = 0;

	std :: cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	std :: cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
}

// 检查两笔交易涉及的ISBN编号是否相同。如果相同输出他们的和，否则报错
void check_data(Sales_data &data1, Sales_data &data2) {
	if ( data1.bookNo == data2.bookNo ) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		// 输出： ISBN， 总销售量，总销售额，平均价格
		std :: cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
			std :: cout << totalRevenue / totalCnt << std :: endl;
		else
			std :: cout << "(no sales)" << std::endl;
	} else {
		std :: cerr << "Data must refer to the same ISBN" << std::endl;
	}

}


int main() {
	// ./a.out < input.txt
	Sales_data data1, data2;
	read_data(data1, data2);
	check_data(data1, data2);
}
