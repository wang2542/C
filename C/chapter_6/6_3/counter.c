#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS	(sizeof(keytab)/sizeof(keytab[0]))

struct key {
	char *word;
	int count;
};

struct key keytab[] = {"a", 0,
       		       "b", 0};

int getword(char *, int);
int binsearch(char *, struct key *, int);

/*
 * count C keywords
 */


void main() {
	printf("we could count how many a or b in our input\n");
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
}

/*
 * binsearch: find word in tab[0] ... tab[n-1]
 */
int binsearch (char *word, struct key tab[], int n) {
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


/*
 * getword: get nex word or character from input
 */
int getword(char *word, int lim) {
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	int t;
	while (isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
    	}

	for (; --lim > 0; w++)
		// isalnum could identify alphabet and number - which include in <ctype.h>
		if (!isalnum(*w = getch())) {
               		ungetch(*w);
      			break;
		}
	*w = '\0';
	return word[0];
}


#define BUFSIZE 100

char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf

// get a (possibly pushed-back) character - from chapter 4.3
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters");
	else
		buf[bufp++] = c;
}
