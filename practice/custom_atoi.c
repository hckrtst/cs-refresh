/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases.
*/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>


static inline bool is_negative(const char * c) 
{
	if (*c == '-') return true;
	return false;			
}

#define ZERO 		48
#define ONE 		49
#define TWO 		50
#define THREE 	51
#define FOUR 		52
#define FIVE 		53
#define SIX 			54
#define SEVEN 	55
#define EIGHT		56 
#define NINE		57
#define SPACE     32

static inline bool is_valid_digit(const char *c, long* d)
{
	*d = 0;
	switch(*c) {
	case ZERO:
	case ONE:		
	case TWO:
	case THREE:
	case FOUR:
	case FIVE:		
	case SIX:
	case SEVEN:
	case EIGHT:
	case NINE:
		*d = (long) (*c - '0');
		return true;
	}
	return false;
}

int myAtoi(char* str) 
{
	char * ptr = str;
	long output = 0;
	bool is_neg = false;
		
	bool bail_condition = false;
	
	//scrub space
	while(*ptr == ' ') ptr++;
		
	if (is_negative(ptr)) {
		is_neg = true;
		//skip over minus
		ptr++;
	}
	
	while(*ptr != '\0') {
			long d = 0;
			
			if (is_valid_digit(ptr, &d)) {
				//printf("%d\n", d);
				output = output * 10 + d;
				if (output > INT_MAX) {
					return INT_MAX;
				} else if (output < INT_MIN) {
					return INT_MIN;
				}
			} else if (*ptr == ' ') {
				break;
			} else {
				//bail_condition = true;
				//output = 0;
				return 0;
			}
			ptr++;
	}
	
	// if negative
	if (is_neg) return ((int)output)*(-1);
	
	return (int)output;
}

int main() 
{
	{
		char s[] = "-2456";
		printf("atoi = %d\n", myAtoi(s));
	}
	
	{
		char s[] = "-2456.567";
		printf("atoi = %d\n", myAtoi(s));
	}
	
	{
		char s[] = "-24569981972543443";
		printf("atoi = %d\n", myAtoi(s));
	}
	
	{
		char s[] = "   -2456    9981";
		printf("atoi = %d\n", myAtoi(s));
	}
}
