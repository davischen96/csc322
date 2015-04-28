// Roy Howie
// Sat Jan 24 16:31:16 EST 2015
// reverse a string

#include <stdio.h>
#include <stdlib.h>

int main () {
	char a[40];
	char *rev;

	printf("enter a sentence to reverse\n");
	scanf("%40[^\n]", a);

	int i = 0;
	while (a[i] != '\0') { i++; }

	rev = (char *) malloc(i * sizeof(char));

	for (int j = 0; j < i; j++) {
		rev[j] = a[i - j - 1];
	}

	printf("%s\n", rev);

	return(EXIT_SUCCESS);
}