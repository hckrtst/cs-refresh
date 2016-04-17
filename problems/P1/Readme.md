# P1 - Is given number a palindrome?
Implement a function that checks whether a positive number is a palindrome or not. For example, 121 is a palindrome, but 123 is not.


# Thought process

Examples of palindromes:
```
134431
22
67876
```

## Option1: convert to string first
Once converted to string we could then iterate the string:
```
check for empty string
check for null string
check for single char --> is this a palindrome? depends on requirements
head = string beginning
tail = end of string
while head != tail
    if str[head] != str [tail] then break
    head++
    tail--    
end
```

## C
This is the most challenging part of this approach. There is no standard itoa() method in C, so we would write our own.

We can use the modulo operator to strip the lower digits of a given number.

> 314 / 10 => 31 with remainder of 4
> This is the same as saying 314 modulo 10

```c

int get_char_r(int i, const char digits[], char outcome[]) {
    if ((i >= 0) && (i <= 9))  {
        outcome[0] = digits[i];
        return 0;
    } else {
        int rem = i % 10;
        int index = (get_char_r(i/10, digits, outcome)) + 1;
        outcome[index] = digits[rem];
        return index;
    }
}

char *my_itoa(const int i) {
    int j = i;
    const int MAX_CHARS = 12;
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char *s = (char*) malloc(sizeof(char) * MAX_CHARS);
    (void) get_char_r(j, digits, s);
    return s;    
}  

```

This itoa has a strange bug though when only single digit is provided:

```
Sankets-Mac-mini:P1 sanket$ ./a.out
Outcome = 345500 --> input is 345500 --> OK
Outcome = 045500 --> input is 0 --> oops!
Outcome = 0 --> input is negative number --> oops!
```


### Useful Reference
* http://www.strudel.org.uk/itoa/

# Adding additional constraints - do not convert number to string
