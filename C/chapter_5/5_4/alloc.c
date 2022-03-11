#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];	// storage for alloc
static char *allocp = allocbuf;		// next free position

char *alloc(int n) {
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;	// old p
	} else {
		return 0;
	}
}

void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
	printf("afree:%p\n",(void *) &allocp);
}

void main() {
	printf("%p\n",(void *) &allocbuf[0]);
	printf("%p\n",(void *) &allocbuf);
	printf("%p\n",(void *) &allocp);
	printf("%p alloc 1 byte\n",alloc(1));
	printf("%p alloc 10001 bytes\n",alloc(10001));
	printf("Before we afree allocp\n");
	printf("%p\n",(void *) &allocbuf[0]);
	printf("%p\n",(void *) &allocbuf);
	printf("%p\n",(void *) &allocp);
	char *ptr = allocp;
	printf("ptr: %p\n",(void *) &ptr);
	afree(ptr);
	printf("%p\n",(void *) &allocbuf[0]);
	printf("%p\n",(void *) &allocbuf);
	printf("%p\n",(void *) &allocp);
}
