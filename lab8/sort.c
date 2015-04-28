// Roy Howie
// Thu Mar 26 01:20:23 EDT 2015

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

pid_t getpid (void);

typedef int *   IntPntr;
typedef int     ArrayOfFiveInts[LENGTH];
typedef IntPntr ArrayOfFivePointers[LENGTH];

// uncomment this and its implementation below for a `-trigraphs` solution
// void bubbleSort (int arr[]);

void bubbleSort (int * arr);
void bubbleSortPointersByPointees (int ** arr);
int  getRandomInt (void);
void init (ArrayOfFiveInts ints, ArrayOfFivePointers pointers);
void printIntegers (int * arr);
void printIntegersByPointer (int ** arr);
void printPointers (int ** arr);

int main (void) {
    // "Declares an array of five integers and an array of five pointers to integers."
    ArrayOfFiveInts myIntegers;
    ArrayOfFivePointers myPointers;

    printf("Currently printing ugly (i.e., very long) integers. See getRandomInt() for nicer numbers.\n\n");

    srand(getpid());
    // "Initializes the arrays (as described above)."
    init(myIntegers, myPointers);

    // "Prints the array of integers."
    printf("~0~\tinitial array of random integers:\n");
    printIntegers(myIntegers);

    printf("~1~\tpointers before sorting:\n");
    printPointers(myPointers);

    // "Sorts the array of pointers (as described above)."
    printf("~2~\tpointers sorted by pointees:\n");
    bubbleSortPointersByPointees(myPointers);
    printPointers(myPointers);

    // "Prints the integers pointed to by the array of pointers."
    printf("~3~\tintegers pointed to by sorted pointers (prints in sorted value, despite unsorted int array):\n");
    printIntegersByPointer(myPointers);

    printf("~4~\tinteger array after pointers were sorted (same as it initially was):\n");
    printIntegers(myIntegers);

    printf("~5~\tinteger array sorted by value:\n");
    bubbleSort(myIntegers);
    printIntegers(myIntegers);

    printf("~6~\tintegers pointed to by pointers (unsorted, since int array was sorted by value, not reference):\n");
    printIntegersByPointer(myPointers);

    return 0;
}

void bubbleSortPointersByPointees (int ** arr) {
    int i, j;
    // This is so ugly. Why do you use the C89 standard instead of C99?
    // aliasing gcc with -std=c99 would make everything 100x nicer
    for (i = 0; i < LENGTH - 1; i++) {
        for (j = 0; j < LENGTH - i - 1; j++) {
            // if the dereferenced value of arr[j] > arr[j+1]
            // i.e., compare the value of the pointers
            if (**(arr + j) > **(arr + j + 1)) {
                // swap the two pointers (not their values);
                int * b = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = b;
            }
        }
    }
}

void bubbleSort (int * arr) {
    int i, j;
    // same as the above bubble sort, except an array of integers was passed,
    // so only need to dereference the comparison once, not twice
    for (i = 0; i < LENGTH - 1; i++) {
        for (j = 0; j < LENGTH - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int b = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = b;
            }
        }
    }
}

/*

// uncomment and compile with -trigraphs for lots of fun...
// this function satisfies the requirement of:
    // <quote>
    // And to make it fun, this function may not contain any [ or ] characters.
    // (You may want to implement it with []s first, and then work out how to remove them later :-).
    // </quote>
// (leaving this commented out, so you don't get attacked by warnings)

void bubbleSort (int arr[]) {
    for (int i = 0; i < LENGTH - 1; i++) {
        for (int j = 0; j < LENGTH - i - 1; j++) {
            if ((arr??(j??)) > (arr??(j+1??))) {
                int b = arr??(j??);
                arr??(j??) = arr??(j+1??);
                arr??(j+1??) = b;
            }
        }
    }
}
*/

int getRandomInt (void) {
    // for testing, much easier to use `return rand() % 100;`
    // OR `static int x = 5; return x--;`
    return rand();
}
void init (ArrayOfFiveInts ints, ArrayOfFivePointers pointers) {
    int i;
    // initialize ArrayOfFiveInts with 5 random integers
    // and ArrayOfFivePointers with their respective memory addresses
    for (i = 0; i < 5; i++) {
        ints[i] = getRandomInt();
        pointers[i] = &(ints[i]);
    }
}
void printIntegers (int * arr) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        printf("\t %d: %d\n", i, *(arr + i));
    }
}
void printIntegersByPointer (int ** arr) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        printf("\t %d: %d\n", i, **(arr + i));
    }
}
void printPointers (int ** arr) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        printf("\t %d: %p\n", i, *(arr + i));
    }
}