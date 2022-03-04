#include <stdio.h>

#define LOWER 0     // lower limit of table
#define UPPER 300	// upper limit of table
#define STEP  20    // step size

void main()
{
	int F;
	for (F = LOWER; F <= UPPER; F =F + 20)
		printf("%3d %6.1f\n", F, (5.0/9.0)*(F-32));
}
