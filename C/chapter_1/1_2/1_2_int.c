#include <stdio.h>

void main()
{
	int F, C;
	int lower, upper, step;

	lower = 0;   // 温度表的下限
	upper = 300; // 温度表的上线
	step = 20;   // 步长
	
	F = lower;
	while (F <= upper) {
		C = 5 * (F - 32) / 9;
		printf("%d\t%d\n", F, C);
		F = F + step;
	}
}
