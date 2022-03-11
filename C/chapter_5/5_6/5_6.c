#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		// max lines to be sorted
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];	// pointers to text lines

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// sort input lines
void main() {
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
	} else {
		printf("error: input too big to sort\n");
	}
}

#define MAXLEN 1000 		// max length of any input line
int getlines(char *, int);
char *alloc(int);

char *alloc(int n) {
        if (allocbuf + ALLOCSIZE - allocp >= n) {
                allocp += n;
                return allocp - n;      // old p
        } else {
                return 0;
        }
}

/*
        getline: read a line into s, return length
*/
int getlines(char s[], int lim)
{
        int c, i;

        for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getlines(line, MAXLEN)) > 0 ) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';	// delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

// writeslines: write output lines
void writelines (char *lineptr[], int nlines) {
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
