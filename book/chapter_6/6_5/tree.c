#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree_(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count: improve version for 6_3 and 6_4 */
void main() {
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree_(root, word);
	treeprint(root);
}

struct tnode *talloc(void);
char *strdup_(char *);

/*
 * addtree: add a node with w, at or below p
 */
struct tnode *addtree_ (struct tnode *p, char *w) {
	int cond;

	if (p == NULL) {
		p = talloc();
		p -> word = strdup_(w);
		p -> count = 1;
		p -> left = p -> right = NULL;
	} else if ((cond = strcmp(w, p -> word)) == 0)
		p -> count++;	/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p -> left = addtree_(p -> left, w);
	else			/* greater than into right subtree */
		p -> right = addtree_(p -> right, w);
	return p;
}

/*
 * treeprint: in-order print of tree p
 */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p -> left);
		printf("%4d %s\n", p-> count, p-> word);
		treeprint(p -> right);
	}
}

/*
 * talloc: make a tnode
 */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_(char *s) {
	char *p;

	p = (char *) malloc (strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
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

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

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
