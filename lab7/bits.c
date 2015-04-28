// Roy Howie
// Tue Mar 17 18:04:15 EDT 2015

#include <stdio.h>
#include <stdlib.h>

#define ODD(X)  ((X) & 01)
#define BITON(X,N) ODD(X >> N)
#define ONES(S) ((1 << (S)) - 1)
#define ALLON(X,S,E) ((((X) >> S) & ONES(E-(S)+1)) == ONES(E-(S)+1))

int main (void) {
    unsigned int u, bitNumber, start, end;

    printf("Enter an integer: ");
    scanf("%ud", &u);
    printf("%u is %s\n", u, (ODD(u) ? "odd" : "even"));

    printf("Enter an integer and a bit number: ");
    scanf("%u %d", &u, &bitNumber);
    printf("%u has bit %d %s\n", u, bitNumber, (BITON(u, bitNumber) ? "on" : "off"));   

    printf("Enter an integer, start and end bit numbers: ");
    scanf("%u %u %u", &u, &start, &end);
    printf("%u has %s those bits on\n", u, (ALLON(u, start, end) ? "all" : "not all"));

    return 0;
}