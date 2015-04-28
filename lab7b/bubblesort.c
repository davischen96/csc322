// Roy Howie
// Sun Jan 11 19:39:38 EST 2015
// bubble sort with "[" or "]" characters
// compile with "gcc -Wall -trigraphs bubblesort.c"

#include <stdio.h>
#include <stdlib.h>

int *getFiveRandomInts () {
	static int random??(5??);
	// srand((unsigned) time(NULL));

	for (int i = 0; i < 5; i++)
		random??(i??) = rand();

	return random;
}

int *bubbleSort(int *arr, int l) {
	for (int i = 0; i < l - 1; i++) {
		for (int j = 0; j < l - i - 1; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				int b = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = b;
			}
		}
	}
	return arr;
}

void printArray(int *arr, int l) {
	for (int i = 0; i < l; i++) {
		printf("%i:\t%i\n", i, *(i + arr));
	}
}

int main () {
	int *unsorted = getFiveRandomInts();
	printf("unsorted:\n");
	printArray(unsorted, 5);

	printf("sorted:\n");
	int *sorted = bubbleSort(unsorted, 5);
	printArray(sorted, 5);

	return(EXIT_SUCCESS);
}