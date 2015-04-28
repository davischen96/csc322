// Roy Howie
// Mon Feb 16 23:23:38 EST 2015

#include <stdio.h>
#include <stdlib.h>

float getPressure (int d) {
    return 1 + d/33.0;
}
float getO2Pressure (int pressure, int percent) {
    return pressure * percent / 100.0;
}

char getPressureGroup (float p) {
    return ((int) (p * 10)) + 65;
}

char * evalBoolean (float p, float min) {
    return p > min ? "true" : "false";
}

int main () {
    int depth = 0, percent = 0;

    printf("Enter depth and %% oxygen:\t");
    scanf("%d %d", &depth, &percent);
    // depth = 99; percent = 36;

    float pressure = getPressure(depth);
    float o2pressure = getO2Pressure(pressure, percent);
    char pressureGroup = getPressureGroup(o2pressure);


    printf("\nambient pressure:\t%4.1f", pressure);
    printf("\nO2 pressure:\t\t%4.2f", o2pressure);
    printf("\nO2 group:\t\t%c\n", pressureGroup);

    printf("\nExceeds maximal O2 pressure:\t\t%s", evalBoolean(o2pressure, 1.4));
    printf("\nExceeds contingency O2 pressure:\t%s\n", evalBoolean(o2pressure, 1.6));

    return 0;
}