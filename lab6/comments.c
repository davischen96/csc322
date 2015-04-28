// Roy Howie
// Thu Mar 5 02:18:18 EST 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOMMENTS 	1000
#define MAXCOMMENTSIZE 	1000

typedef enum { false, true } bool;

void printComment (char * word, int n) {
	printf("#%d:\n", n);
	int i = 0;
	while (*(word + i) != '\0') {
		printf("%c", *(word + i++));
	}
	printf("\n");
}

int main (void) {
	bool inString = false, inComment = false, singleLineComment = false;
	char * comments[MAXCOMMENTS];
	int numberOfComments = 0;
	// temp temporarily holds a comment before its pointer is stored in comments[]
	char temp[MAXCOMMENTSIZE];
	// keeps track of the last character stored in temp
	int tempIndex = 0;
	// input is the current character
	char input, lastChar;
	// to loop through and print comments later on
	int i = 0;

	while ((input = getchar()) != EOF) {
		if (inComment) {
			temp[tempIndex++] = input;
			// if we are at the end of a line and this is a single-line comment
			// OR
			// the last character read was an asterisk and input is a slash
			if ((input == '\n' && singleLineComment) || (lastChar == '*' && input == '/')) {
				// add the null terminator to our string in temp
				// very important since, when printing comments, this is how we'll detect
				// the end of a comment
				temp[tempIndex] = '\0';
				// we are no longer in any type of comment, so set these booleans to false
				singleLineComment = inComment = false;
				// dynamically allocate memory equal to the size of our string held in temp
				// and assign it to the next open index in comments, an array of pointers
				comments[numberOfComments] = malloc(sizeof(char) * tempIndex);
				strcpy(comments[numberOfComments], temp);
				// was going to in-line this above, I figured that was bad practice
				++numberOfComments;
				// temp is now "empty" (not really, but we're free to write over it)
				tempIndex = 0;
			}
		} else {
			// if we are not inside a string
			// AND
			// the last character was a slash
			// AND
			// the current character is a slash OR an asterisk
			if (!inString && lastChar == '/' && (input == '/' || input == '*')) {
				// if the current character is a slash, this must be a single-line comment
				singleLineComment = input == '/';
				// duh
				inComment = true;
				// set temp[0] to a slash (all comments start with slash)
				temp[0] = '/';
				// set temp[1] to input (an asterisk or a slash)
				temp[1] = input;
				// temp already has two characters; set tempIndex to 2
				tempIndex = 2;
			// if the most recent character is a quotation mark
			} else if (input == '\"' && lastChar != '\\') {
				// we are now in the opposite string "state"
				inString = !inString;
			}
		}
		// set the most recently read character to lastChar, so that it can be used
		// in the next iteration of the loop
		lastChar = input;
	}
	printf("PRINTING COMMENTS:\n");
	for (i = 0; i < numberOfComments; i++) {
		printComment(comments[i], i + 1);
		// no memory leaks!
		free(comments[i]);
	}
	return 0;
}