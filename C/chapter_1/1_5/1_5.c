#include <stdio.h>

void main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

	/*
		当我们声明变量c的时候，它必须足够大。能储存任何可能的字符之外还要储存结束符EOF。
	*/
}
