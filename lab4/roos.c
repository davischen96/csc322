// Roy Howie
// Thu Feb 19 20:01:48 EST 2015

#include <stdio.h>
#include <stdlib.h>
#define KILLCONSTANT 1.47
#define ROADWIDTH 0.01

float getKills (int roos, float square, float len) {
    return KILLCONSTANT * len * ROADWIDTH * roos / (square * square);
}

int main () {
    float s = 1.0, l = 1.0;
    int roos = 0;

    printf("Enter side of square in km:\t");
    scanf("%f", &s);
    printf("Enter roads length in km:\t");
    scanf("%f", &l);
    printf("Enter number of 'roos:\t\t");
    scanf("%d", &roos);
    printf("Expected number of kills is:\t%5.1f\n", getKills(roos, s, l));

    return 0;
}