#include <stdio.h>

#define STORED_VALUE 1234.56789

/*Write a program that stores the value 1234.56789 in a double variable,
 then displays it in the following different ways. 
 
* with exactly 2 decimal places       1234.57
* in a field that is 15 columns wide. Mark the beginning and end of the field with / characters  /    1234.567890/
* as above, but left-justified /1234.567890    /
*/
int main(void){
	double double_var = STORED_VALUE;
	
	printf("with exactly 2 decimal places: %.2f\n", double_var);
	printf("15 columns wide: /%15f/\n", double_var);
	printf("left-justified: /%-15f/\n", double_var);
	
	return 0;
}
