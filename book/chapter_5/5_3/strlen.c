#include <stdio.h>

/*
 * strlen: return length of string s
 */

int strlens(char *s) {
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;

	return n;
}

void main(){
	printf("%d\n", strlens("hello, world"));

}
