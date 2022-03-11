#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1

// install(s, t)	将名字s和替换文本t记录到某个表，其中s和t仅仅是字符串
// loopup(s)		在表中查找到s，若找到，则返回指向该处的指针，若没找到返回NULL
// 链表种的每个块都是一个结构，他包含一个指向名字的指针，一个指向替换文本的指针以及一个指向该链表后继块的指针。（如果后继块指针为NULL，则表明链表结束）

struct nlist {
	struct nlist *next;	// next entry in chain
	char *name;		// defined name
	char *defn;		// replacement text
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; 	// pointer table

// hash: from hash value for string s
unsigned hash(char *s) {
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

// lookup: look for s in hashtab
struct nlist *lookup(char *s) {
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np -> next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

char *strdup_(char *s) {
        char *p;

        p = (char *) malloc (strlen(s) + 1);
        if (p != NULL)
                strcpy(p, s);
        return p;
}

// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn) {
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np -> name = strdup_(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np -> next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np -> defn);
	if ((np->defn = strdup_(defn)) == NULL)
		return NULL;
	return np;
}

void main() {
	char *input = "Wang";
	char *input2 = "Jingzhou";
	if (lookup(input) == NULL)
		printf("We could not found the input\n");
	install("Wang","Jingzhou");
	if (lookup(input) == NULL)
		printf("We could not found the input\n");
	else {
		struct nlist *result = lookup(input);
		printf("%s %s\n", result -> name, result -> defn);
	}


}
