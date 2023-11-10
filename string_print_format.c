#include <stdio.h>
/*Write a program that gets the user's name and stores it in a string 
then displays it in the following different ways.
*/
int main(void){
	char name[20];
	printf("Enter Name:");
	scanf("%s", name);
	
	//  in a field that is 10 columns wide.
	printf("/%10s/\n", name);
	printf("/%.3s/\n", name);
	
	return 0;
}
