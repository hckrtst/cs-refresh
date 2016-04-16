#include <stdlib.h>
#include <stdio.h>

int check_valid_string(const char* const s) {
	char *ptr = s;
	int res = 0;
	
	do {
		// null pointers are invalid
		if (s == NULL) break;

		// empty strings are not valid
		if (*ptr == NULL) break;

		int counter = 0;
		
		// TODo future optimization
		// if only one letter/word then not valid
		// a letter followed by space(s) followed by letter is good
		while (*ptr != NULL) {
			res++;
			ptr++;	
		}
	} while (0);
	return res;	
}

void swap(char* const s, const int h, const int t) {
	char temp = s[h];
	s[h] = s[t];
	s[t] = temp;
}

void reverse_word(char* const s, const int h, const int t) {
	// reverse the whole string
	int tail = t;
	int head = h;

	while(head <= tail) {
		swap(s, head, tail);
		head++;
		tail--;
	}		
}

int get_tail(const int head, char * const s) {
	int tail = head;
	char *ptr = s;
	while ((*ptr != NULL) && (*ptr != ' ')) {
		ptr++;
		tail++;
	}
	return (tail - 1);
}

/*
*  
*/
int reverse_string_inline(char* const s) {
	const int len = check_valid_string(s);
	if (len  > 0) {
		printf("Str = %s\n", s);

		// reverse the whole string
		int tail = len - 1;
		int head = 0;

		while(head <= tail) {
			swap(s, head, tail);
			head++;
			tail--;
		}

		printf("Intermediate string = %s\n", s);

		// iterate over each word and re-reverse it
		head = 0;
		char *cursor = s;
		while (*cursor != NULL) {
			while (*cursor != NULL && *cursor == ' ') {
				head++;
				cursor++;
			}

			// move tail up
			tail = head;
			while (*cursor != NULL && *cursor != ' ') {
				tail++;
				cursor++;
			}

			reverse_word(s, head, tail-1);
			// we need to move head up
			head = tail;			
		}

		printf("Reversed string = %s\n", s);

	}
	else {
		printf("skipping for invalid data\n");
	}
	return 0;
}

int main(int argc, char** argv) {
	{
		char mystring[]= " this     is a test";
		reverse_string_inline(mystring);
	}

	{
		char mystring[]= "";
		reverse_string_inline(mystring);
	}

	{
		char mystring[]= " ";
		reverse_string_inline(mystring);
	}

	{
		char mystring[]= "thisisatest";
		reverse_string_inline(mystring);
	}

	{
		char* mystring = NULL;
		reverse_string_inline(mystring);
	}
	return 0;	
}

