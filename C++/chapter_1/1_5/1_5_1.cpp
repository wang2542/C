#include <iostream>
#include "Sales_item.h"

void r_w_items() {
	Sales_item book;
	std :: cin >> book;
	std :: cout << book << std :: endl;
}

void add_items() {
	Sales_item item1, item2;;
	std :: cin >> item1 >> item2;
	std :: cout << item1 + item2 << std :: endl;
}

int main() {
	// ./a.out < r_w.txt
	// r_w_items();

	// ./a.out < add.txt
	add_items();
}
