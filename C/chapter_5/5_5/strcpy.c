#include <stdio.h>
#include <stdlib.h>

/*
 * strcpy: copy t to s; array subscript version
 */

void strcpy_ary(char *s, char *t) {
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

/*
 * strcpy: copy t to s; pointer version
 */

void strcpy_ptr(char *s, char *t) {
	int i;

	i = 0;
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}


/*
 * strcpy: copy t to s; pointer version 2
 */

void strcpy_ptr_2(char *s, char *t) {
	int i;

	i = 0;
	while ((*s++ = *t++) != '\0');
}


/*
 * strcpy: copy t to s; pointer version 3
 */

void strcpy_ptr_3(char *s, char *t) {
	while (*s++ = *t++);
}

void main() {
	char t_ary[] = "I'm ary t";
	char s_ary[10] ;
	strcpy_ary(s_ary, t_ary);
	printf("t: %s \n", t_ary);
	printf("s: %s \n", s_ary);


	char *t = "I'm ptr t";
	char *s ;
	s = malloc(sizeof(char));	// if we don't malloc for s , s does not have a pointee yet
	
	
	strcpy_ptr(s, t);
	printf("t: %s \n", t);
	printf("s: %s \n", s);
	
	char *t_2 = "I'm t_2";
	char *s_2 = "";
	s_2 = malloc(sizeof(char));	// if we don't malloc for s , s does not have a pointee yet
	strcpy_ptr_2(s_2, t_2);
	printf("t: %s \n", t_2);
	printf("s: %s \n", s_2);


	char *t_3 = "I'm t_3";
	char *s_3 = "";
	s_3 = malloc(sizeof(char));	// if we don't malloc for s , s does not have a pointee yet
	strcpy_ptr_3(s_3, t_3);
	printf("t: %s \n", t_3);
	printf("s: %s \n", s_3);
	
}

// refer: http://cslibrary.stanford.edu/106/#:~:text=Pointer%20assignment%20between%20two%20pointers,same%20reference%20as%20another%20pointer.
