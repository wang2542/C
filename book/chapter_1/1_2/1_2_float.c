#include <stdio.h>

void main()
{
	float F, C;
	float lower, upper, step;

	lower = 0;   // 温度表的下限
	upper = 300; // 温度表的上线
	step = 20;   // 步长
	
	F = lower;
	while (F <= upper) {
		C = (5.0 / 9.0) * (F - 32.0);
		printf("%3.0f\t%6.1f\n", F, C);
		F = F + step;
	}
}
