/* Write a program that asks for an integer. 
It should use a loop to count backwards by ones from that number
until it gets to a number 5 smaller. */

#include <stdio.h>

#define NUM_TO_REDUCE 5

int main (void) {
	int num_picked;
	int counter;
	
	printf("Pick a number: ");
	scanf("%d", &num_picked);
	printf("Let me count backwards.... ");
	for(counter = 0; counter <= NUM_TO_REDUCE; ++counter){
		printf("%d ", num_picked - counter);
	}
	
	printf("\nGot it! %d - %d is %d", num_picked, NUM_TO_REDUCE, num_picked - NUM_TO_REDUCE);
	
	return 0;
}
