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
Once converted to string we could then iterat the string:
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



# Adding additional constraints - do not convert number to string
