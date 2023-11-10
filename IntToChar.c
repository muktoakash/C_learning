#include <stdio.h>


//Write a program that gets an int from the user, 
// and displays the value both as an int and a char.
int main(void){
	int input;
	
	printf("Enter an integer:");
	scanf("%d", &input);
	
	printf("ASCII code %d correspondes to character %c", input, input);
	
	return 0;
}
