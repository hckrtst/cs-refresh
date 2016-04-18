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
> This is the same as saying 314 modulo 10 (SEE UPDATE BELOW FOR EDIT)

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
Outcome = 945500 --> input is 9 --> oops!
Outcome = 0 --> input is negative number --> oops!
```

The issue seen when inout is 0 is that we got a chunk of uninitialized memory. We can fix this by using `calloc`.

We also need to handle negatives properly. That should be simple check.

UPDATE: I was running into a crash when moved main() to a new file. Oddly enough, when the address was passed back to `main()` from `myatoi()` it was
`0x0000000000400000` instead of `0x0000000100400000`. The address received could not be dereferenced resulting in a crash. 

```
(lldb) memory read 0x0000000100400000
0x100400000: 33 34 35 35 30 30 00 00 00 00 00 00 00 00 00 00  345500..........
0x100400010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
(lldb) memory read 0x0000000000400000
error: memory read failed for 0x400000
(lldb) s = 0x0000000100400000
error: invalid thread index '='.
(lldb) memory read 0x0000000100400000
0x100400000: 33 34 35 35 30 30 00 00 00 00 00 00 00 00 00 00  345500..........
0x100400010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
(lldb) print &s
(char **) $5 = 0x00007fff5fbffab8
(lldb) print *s
error: Couldn't apply expression side effects : Couldn't dematerialize a result variable: couldn't read its memory
(lldb) print s
(char *) $7 = 0x0000000000400000 ""
````

This was resolved by passing in pointer-to-pointer-to-char from callee as a param and using it directly during `calloc()`.

See [myitoa.c](myitoa.c) for complete solution.

Now that we have that working we can actually use the function to covert to string and do the iteration.


### Useful Reference
* http://www.strudel.org.uk/itoa/

# Adding additional constraints - do not convert number to string
