/* Write a program that prompts the user to enter 10 double numbers. */

#include <stdio.h>

#define SIZE 10 // Size of the array

//prototypes:
void read_numbers(double ar[], int size);
void show_numbers(double ar[], int size);

//driver:
int main(void) {
	double nums[SIZE];
	read_numbers(nums, SIZE);
	show_numbers(nums, SIZE);
	return 0;
}

// read_numbers(ar_nums, size) read size amount of numbers and stores them in ar_nums
// side-effects: mutates ar_nums
void read_numbers(double ar_nums[], int size){
	printf("Please ender %d numbers\n", size);
	
	int i = 0;
	while((i < size) && scanf("%lf", &ar_nums[i]) == 1){
		i++;
	}
}

// show_numbers(ar_nums, size) displays the contents of ar_nums
void show_numbers(double *ar_nums, int size){
	printf("\nYour numbers are:\n");
	int i;
	for(i = 0; i < size; i++){
		printf("%lf ", *(ar_nums+i));
	}
}
