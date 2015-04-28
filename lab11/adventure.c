// Roy Howie
// Sat Apr 11 23:45:29 EDT 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[128];
typedef enum { false, true } bool;
typedef enum { bird, fish, insect, mammal } AnimalType;
typedef struct {
    AnimalType type;
    double size;
    String name;
} Animal;

bool            enterAnimal         (Animal * a);
AnimalType      getTypeFromString   (String type);
char *          getStringFromType   (AnimalType type);
void            makeRoom            (Animal *** found, int * size);
void            printAnimals        (Animal ** found, int size);


int main (void) {
    int maxSize = 1, currentIndex = -1;
    Animal ** found = malloc(sizeof(Animal *));

    while (true) {
        Animal * a = malloc(sizeof(Animal));
        if (++currentIndex >= maxSize) {
            makeRoom(&found, &maxSize);
        }
        if (!enterAnimal(a)) {
            break;
        } else {
            *(found + currentIndex) = a;            
        }
    }

    printAnimals(found, currentIndex);

    return 0;
}

bool enterAnimal (Animal * a) {
    String type;

    printf("Enter animal information (\"exit\" as name to exit)\n");

    printf("What is the name: ");
    scanf("%s", a->name);

    if (!strcmp(a->name, "exit")) {
        return false;
    }

    printf("What is the size: ");
    scanf("%lf", &a->size);

    printf("What is the type: ");
    scanf("%s", type);

    a->type = getTypeFromString(type);

    return true;
}
AnimalType getTypeFromString (String type) {
    if (!strcmp(type, "bird")) {
        return bird;
    } else if (!strcmp(type, "fish")) {
        return fish;
    } else if (!strcmp(type, "insect")) {
        return insect;
    } else if (!strcmp(type, "mammal")) {
        return mammal;
    } else {
        perror("invalid animal type. exiting");
        exit(-1);
    }
}
char * getStringFromType (AnimalType type) {
    switch (type) {
        case bird:      return "bird";
        case fish:      return "fish";
        case insect:    return "insect";
        case mammal:    return "mammal";
        default:        return "error";
    }
}
void makeRoom (Animal *** found, int * size) {
    *size *= 2;
    *found = realloc(*found, *size * sizeof(Animal *));
    if (*found == NULL) {
        perror("memory could not be reallocated. exiting.");
        exit(-1);
    }
}
void printAnimals (Animal ** found, int size) {
    int i;
    Animal * a;
    printf("The following new species were found:\n");
    for (i = 0; i < size; i++) {
        a = *(found + i);
        printf("%-25s has size %5.2f and is a %s\n", a->name, a->size, getStringFromType(a->type));
    }
}