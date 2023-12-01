/*The goal of this program is to get two numbers from the user and sort them. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prototype:
int sort_two(int *n1, int *n2);

int main(void){
	char input[50];
	int num1, num2;
	int need_swapped;
	
	printf("Please enter first number: \n");
	gets(input);
	num1 = atoi(input);
	
	printf("Please enter second number: \n");
	gets(input);
	num2 = atoi(input);
	
	need_swapped = sort_two(&num1, &num2);
	
	printf("Integers in sorted order: %d, %d\n", num1, num2);
	
	if (need_swapped){
		printf("Your numbers needed to be swapped.");
	} else {
		printf("Nice! Your numbers were already sorted.");
	}
	
}

// sort_two(n1, n2) sorts n1 and n2 from smallest to largest
int sort_two(int *n1, int *n2){
	int temp = *n2;
	if (*n1 <= *n2)
		return 0;
	*n2 = *n1;
	*n1 = temp;
	return 1;
	
}
