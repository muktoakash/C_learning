#include <stdio.h>
#define MAX 100
#define MIN 1

int guess_wrong(guess, max, min){
	char ch;
	
	if ((guess < 1) || (guess > 100)){
		return 1;
	}
	fflush(stdin);
	
	printf("Is your number %d? Enter (y)es or (n)o.\n", guess);
	
 	if (getchar() != 'y'){/* get response, compare to y */
		printf("Is the guess too (h)igh or too (l)ow? Enter h or l: ");
		fflush(stdin);
		
		ch = getchar();
		
		switch (ch) {
			case 'h':
				if (guess == MIN){
					printf("I cannot go any lower. Your number must be %d.\n", MIN);
					return 0;
				}	
				max = guess;
				guess = (guess + min)/2;
				return guess_wrong(guess, max, min);
			
			case 'l':
				if (guess == MAX){
					printf("I cannot go any higher. Your number must be %d.\n", MAX);
					return 0;
				}
				if (guess == MAX-1){
					return guess_wrong(MAX, MAX, MIN);
				}
				min = guess;
				guess = (guess + max)/2;
				return guess_wrong(guess, max, min);
				
			default:
				printf("The program only accepts h or l, try again.\n");
				return guess_wrong(guess, max, min);
		}
	}
	return 0;
}

int main(void)
{
 int guess = 50; //initial guess
 int max_guess = MAX;
 int min_guess = MIN;
 
 if(!guess_wrong(guess, max_guess, min_guess)){
 	printf("I knew I could do it!\n");	
 } else {
 	printf("Opps! Something went wrong!!");
 }
 
 return 0;
} 
