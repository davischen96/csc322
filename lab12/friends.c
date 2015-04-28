// Roy Howie
// Wed Apr 22 22:16:06 EDT 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ever (;;)

typedef char String[128];
typedef enum { false, true } bool;
typedef struct node {
    String name;
    struct node * next;
    struct node * bff;
} LLNode;

bool        addNation               (LLNode * head, LLNode * newNode);
void        addBestFriendsFiveEver  (LLNode * head);
LLNode *    findFriendInList        (LLNode * head, String name);
void        printAndFreeNodes       (LLNode * head);


int main (void) {
    LLNode * head = malloc(sizeof(LLNode));

    head->next = NULL;

    printf("enter -1 to stop entering nations\n");

    while ( addNation(head, malloc(sizeof(LLNode))) ) ;

    if (head->next == NULL) {
        printf("\nyou did not enter any nodes! ='( exiting program.\n");
        free(head);
        return -1;
    }

    addBestFriendsFiveEver(head);

    printf("\n5 is more than 4. Hence, a best friend five-ever is more than a BFF (best friend 4ever)!!\n\n");

    printAndFreeNodes(head);

    return 0;
}

bool addNation (LLNode * head, LLNode * newNode) {
    printf("Enter nation name:\t");
    scanf("%s", newNode->name);

    if (!strcmp(newNode->name, "-1")) {
        free(newNode);      // not attached to anything, so must be freed now
        return false;
    } else {
        newNode->next = head->next;
        head->next = newNode;
        return true;
    }
}

void addBestFriendsFiveEver (LLNode * head) {
    String nameOfBFF;
    LLNode * foundFriend = NULL;
    LLNode * dummy = head;

    while (dummy->next != NULL) {
        dummy = dummy->next;

        for ever {
            printf("Enter BEST FRIEND FIVE-EVER for %s:\t", dummy->name);
            scanf("%s", nameOfBFF);

            if (!strcmp(nameOfBFF, dummy->name)) {
                printf("You can't be BFFs with yourself (that is far too sad). Try again!\n");
            } else if ((foundFriend = findFriendInList(head, nameOfBFF)) == NULL) {
                printf("That BFF either does not exist. Try again!\n");
            } else {
                break;
            }
        }

        dummy->bff = foundFriend;
    }
}

LLNode * findFriendInList (LLNode * head, String name) {
    LLNode * dummy = head;

    while (dummy->next != NULL) {
        dummy = dummy->next;
        if (!strcmp(name, dummy->name)) return dummy;
    }

    return NULL;
}

void printAndFreeNodes (LLNode * head) {
    int i = 0;
    LLNode * dummy;

    // put the shift-forward logic first, so head is skipped
    while (head->next != NULL) {
        dummy = head->next;
        free(head);
        head = dummy;
        printf("%d.  %s is\t\t~~~BEST FRIENDS FIVE-EVER~~ with\t\t%s\n", ++i, head->name, head->bff->name);
    }
    // our last node won't go through the loop, so free it now
    free(head);
}