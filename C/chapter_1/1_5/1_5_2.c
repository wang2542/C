#include <stdio.h>

void main()
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);

	// use ctrl+d to type EOF in Unix or Linux
}
