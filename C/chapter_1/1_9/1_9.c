#include <stdio.h>

#define MAXLINE 1000 // maximum input line length

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

/*
	print the longest input line
	读入一组文本行，并把最长的文本行打印出来
*/
void main()
{
	int len;				// current line length
	int max;				// maximum length seen so far
	char line[MAXLINE]; 	// current input line
	char longest[MAXLINE];	// longest line saved here

	max = 0;
	while ((len = getline_(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	
}

/*
	getline: read a line into s, return length
*/
int getline_(char s[], int lim)
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

/*
	copy: copy 'from' into 'to'; hassume to is big enough
*/

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
