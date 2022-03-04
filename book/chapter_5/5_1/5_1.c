#include <stdio.h>

void main() {
	int x = 1, y = 2, z[10];
	int *ip;	// ip is a pointer to int
	ip = &x; 	// ip now points to x
	printf("%d \n", *ip);
	y = *ip;	// y is now 1
	printf("%d \n", y);
	*ip = 0;	// x is now 0
	printf("%d \n", x);
	ip = &z[0];	// ip now points to z[0]
	printf("%d \n", *ip);
	z[0] = 3;
	printf("%d \n", *ip);

}
