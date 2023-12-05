/*  Write a program that uses fprintf to print to stdout.
Note that stdout is not a file name, 
but an existing FILE* that always gets opened when you run a program. 
(Usually sending information to stdout causes it to appear on the screen.)
This program should only be a few lines long -- there isn't much to do.
*/

#include <stdio.h>

int main (void) {
	fprintf(stdout, "Hello World!\n");
	
	return 0;
}
