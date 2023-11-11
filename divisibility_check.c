/* Write a program that looks for the first number over 100 
that is divisible both by 3 and 4.
*/

#include <stdio.h>

#define FIRST_DIV 3
#define SECOND_DIV 4
#define NUM_START 100
#define TRUE 1

int main ( void ) {
	int num;
	int result_1;
	int result_2;
	
	num = NUM_START;
	
	do {
		result_1 = num % FIRST_DIV;
		result_2 = num % SECOND_DIV;
		
		if (result_1 && result_2) {
			printf("%d is not divisible by %d or by %d\n", num, FIRST_DIV, SECOND_DIV);
			num++;
			continue;
		} else if (result_1) {
			printf("%d is divisible by %d, but not by %d\n", num, SECOND_DIV, FIRST_DIV);
			num++;
			continue;
		} else if (result_2) {
			printf("%d is divisible by %d, but not by %d\n", num, FIRST_DIV, SECOND_DIV);
			num++;
			continue;
		} else {		
			printf("%d is the first number over %d that is divisible by %d AND %d", num,
				 	NUM_START, FIRST_DIV, SECOND_DIV);
			break;
		}
	} while (TRUE);
		
	return 0;
}
