/* Write a program that reads input from a file up to EOF and reports
 
a) the number of words
b) the number of uppercase letters
c) the number of lowercase letters,
d) the number of punctuation characters,
e) the number of digits.
*/

#include <stdio.h>
#include <ctype.h>

#define NAMESIZE 100

// Function prototypes
char trim_white_space(FILE * fp, char * pch);
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
    
    
    char filename[NAMESIZE];   /* generous enough for directory names to be included in file name. */
    FILE *fp;
    
    int read_success; // to see if fscanf was successful or if EOF was reached
    
    //variable initialization: everything set to zero.
    lowercase_count = uppercase_count = num_count = words_count = punctuation_count = 0; 
    //set address of words_count to the pointer
    ad_word_ct = &words_count;

    printf("What file do you wish to read? ");
      scanf(" %s", filename);
 
      /* open the file */
      if ((fp=fopen(filename, "r")) == NULL)
      {
            printf("Can't open %s.\n", filename);
            exit(1);
      }
      
    
    read_success = trim_white_space(fp, &ch);
    
    while (read_success == 1) 
    {
        if (islower(ch)) // using functions from ctype.h
            lowercase_count++;
        else if (isupper(ch)) // using functions from ctype.h
            uppercase_count++;
        else if (isdigit(ch)) // using functions from ctype.h
            num_count++;
        else
			punctuation_count += is_end_word(ch, ad_word_ct); // check for word ending

		read_success = fscanf(fp, "%c", &ch); // get next character
	}
	words_count++; // to count the last word
	
    printf("\nNumber of words = %d, lowercase letters = %d, uppercase letters = %d, "
           "digits = %d, number of punctuations = %d\n",
            words_count, lowercase_count, uppercase_count, num_count, punctuation_count);
            
    return 0;
}


/* trim_white_space(fp, pch) discards any white space at the beginnning of the file 
and returns whether reading the first non-space character via pch was a success.
SIDE-EFFECTS: mutates pch, mutates fp*/
char trim_white_space(FILE * fp, char * pch){
	int read_success;
	
	read_success = fscanf(fp, "%c", pch);
	while(read_success == 1 && isspace(*pch)){ // take advantage of short-circuits
		continue; //do nothing
	} 
	
	return read_success;
}

/* is_end_word(c, wd_ct) increases the word count by 1 via indirection on pointer wd_ct,
and returns 1 if c is punctuation, 0 otherwise. */
int is_end_word(char c, int * wd_ct){
	(* wd_ct)++;      // increment count word
	if (ispunct(c)){
    	return 1; //end of word reached via punctuation
	}
	return 0; // word ended via space
}
