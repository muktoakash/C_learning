/*
Devise a function my_min(x,y) that returns the smaller of two float values, 
and test the function with a driver. 
The driver should prompt the user for input 
and then display the value returned by the my_min() function.
*/

#include <stdio.h>

// function prototype
// my_min(x, y) returns the smaller of x and y
float my_min(float x, float y);

// Driver
int main (void) {
	float num1, num2; //variables for input
	
	printf("Enter the first number: ");
	
	while (scanf("%f", &num1) != 1) {
		fflush(stdin);
		printf("Something went wrong, please enter the first number again: ");
	} 
	
	fflush(stdin);
	
	printf("Enter the second number: ");
	
	while (scanf("%f", &num2) != 1) {
		fflush(stdin);
		printf("Something went wrong, please enter the second number again: ");
	} 
	
	printf("The minimum of %f and %f is %f\n", num1, num2, my_min(num1, num2));
	
	printf("bye!");
}

// function
float my_min(float x, float y){
	return x * (x <= y) + y * (x > y); // return the smaller of the two numbers
}
