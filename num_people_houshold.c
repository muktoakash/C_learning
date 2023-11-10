/* calculate the number of people in a household */
#include <stdio.h>
int main(void)
{
    int adults = 2;
    int kids = 3;
    int total_people;
    
	total_people = adults - kids;
	printf("There are %d people here.\n", total_people);
    
    return 0;
}
