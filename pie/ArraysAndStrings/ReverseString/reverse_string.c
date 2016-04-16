#include <stdlib.h>



int check_valid_string(const char* const s) {
	char *ptr = s;
	int len = 0;
	
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
			counter++; 
		}
		len = counter - 1;
	} while (0);
	return len;	
}

void swap(char* s, const int h, const int t) {
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

/*
*  
*/
int reverse_string_inline(char* const s) {
	// string should not be null
	if (s == NULL) return -1;

	const int len = check_valid_string(s);
	if (len  > 0) {
		printf("Str = %s\n", s);

		// reverse the whole string
		int tail = len;
		int head = 0;

		while(head <= tail) {
			swap(s, head, tail);
			head++;
			tail--;
		}

		printf("Intermediate strning = %s\n", s);

		// iterate over each word and re-reverse it
		head = 0;
		tail = head;
		int cursor = 0;
		while (head <= len) {
			if (*cursor != ' ') {
				tail++;
			} else if (*cursor == ' ') {
				head++;
				tail++;
			} 
			else {
				reverse_word(s, head, tail);
				// move up head and tail
				tail++;
				head = tail;
				
			}
		}

		printf("Reversed string = %s\n", s);

	}
	
}

int main(int argc, char [] argv) {
	char* mystring = "this is a test";
	reverse_string_inline(mystring);
	return 0;	
}

