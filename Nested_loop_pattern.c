/* Assignment 3 question 2 - Mukto Akash */
/* Use a loop inside a loop to create the following pattern:
 
            ABCDE
            ABCD
            ABC
            AB
            A
*/

#include <stdio.h>

#define CHAR_START 'A'
#define CHAR_END 'E'

int main (void) {
	char ch;
	int counter;
	
	for (counter = CHAR_END - CHAR_START; counter >=0; counter--){
		ch = CHAR_START;
		while (ch - CHAR_START <= counter) {
			printf("%c", ch);
			ch++;
		}
		
		if (counter)
			printf("\n");
	}
}
