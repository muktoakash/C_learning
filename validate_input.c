#include <stdio.h>
#include <ctype.h> // For the isspace() function
 


int get_int(void);          /* validate that input is an integer */
 
int main(void)
{
   int result;
   
   /* Display a message to the user that to terminate input s/he should enter the value 0. */
   printf("Enter some integers. When you are done, enter 0 (zero).\n");
   
   /* Write a loop that uses get_int() to get an integer and stops when the integer it gets is 0. */
   /* No requirement is mentioned to print the integer that is input, so not doing that. */
   while((result = get_int())){
	   printf("I got the number %d.\n", result);
	}
   		
   return 0;
}
 
int get_int(void)
{
    int input;
 	char ch;
 	
 	while (scanf("%d", &input) != 1){
		while (!isspace(ch = getchar())){
			putchar(ch); // dispose of bad input
		}
		printf(" is not an integer\n");
	}
	
	 return input;
}
