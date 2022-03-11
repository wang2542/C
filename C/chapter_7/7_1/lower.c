#include <stdio.h>
#include <ctype.h>

// lower: convert input to lower case
void main() {
	int c;

	while ((c = getchar()) != EOF)
		putchar(tolower(c));

}
