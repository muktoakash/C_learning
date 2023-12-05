/* Write a program that reads input from the keyboard up to EOF and reports
 
a) the number of words
b) the number of uppercase letters
c) the number of lowercase letters,
d) the number of punctuation characters,
e) the number of digits.
*/

#include <stdio.h>
#include <ctype.h>

// Function prototypes
char trim_white_space(void);
int is_end_word(char c, int * wd_ct);        

int main(void)
{
	// variable declaration
    char ch;               // read in character
    int lowercase_count;  // count of lowercase characters
    int uppercase_count;        // number of uppercase characters
    int num_count;       // number of digits
    int words_count;      // number of words
    int punctuation_count;      // number of punctuation marks
    int * ad_word_ct; // pointer to change value of words count using side-effect
    
    //variable initialization: everything set to zero.
    lowercase_count = uppercase_count = num_count = words_count = punctuation_count = 0; 
    //set address of words_count to the pointer
    ad_word_ct = &words_count;

    printf("Enter text (EOF to quit):\n");
    
    ch = trim_white_space();
    
    while (ch != EOF) 
    {
        if (islower(ch)) // using functions from ctype.h
            lowercase_count++;
        else if (isupper(ch)) // using functions from ctype.h
            uppercase_count++;
        else if (isdigit(ch)) // using functions from ctype.h
            num_count++;
        else // must have reached end of word
			punctuation_count += is_end_word(ch, ad_word_ct); // check fo how word ended

		ch = getchar();
	}
	words_count++; // to count the last word
	
    printf("\nNumber of words = %d, lowercase letters = %d, uppercase letters = %d, "
           "digits = %d, number of punctuations = %d\n",
            words_count, lowercase_count, uppercase_count, num_count, punctuation_count);
            
    return 0;
}


/* trim_white_space() removes any white space at the beginnning of the text 
and returns the first non-space character*/
char trim_white_space(void){
	char ch;
	
	while(isspace(ch = getchar())){
		continue; //do nothing
	} 
	
	return ch;
}

/* is_end_word(c, wd_ct) increases the word count by 1 via indirection on pointer wd_ct,
and returns 1 if c is punctuation, 0 otherwise.
*/
int is_end_word(char c, int * wd_ct){
	(* wd_ct)++;      // increment count word
	if (ispunct(c)){
    	return 1; //end of word reached via punctuation
	}
	return 0; // word ended via space
}
