#Problem
Determine if two words are anagrams

#Notes
WOrds are anagrams if they have the same letters (with same frequency)

##Constraints and Assumptions
* ascii
* may only need to consider letters?

##Examples
* abcdfee and fdceeba are anagrams
* abcdl and dlvc are not

## Approach
We can use word frequencies to determine whether two words are anagrams

#Pseudocode

int str1cnt[26];
int str2cnt[26];

for  s1
   for each char c
      get index = getindex(c)
      str1cnt[index]+=1
repeat for s2
if counts match then
   declare anagram

#Postmortem
* CAUTION: Be careful with using the correct count of an array. To get the correct count of elements
of an array use `sizeof(array)/sizeof(array[0])`. `sizeof(array)` gives us the *total* bytesize, while
`szeof(array[0]` gives us the bytesize of one element. Hence the division gives us the element count.

* While this works to zero initialize an array
```c
int str1Cnt[26] = {0};
int str2Cnt[26] = {};
```
It does *not* work as expected to initialize array to some other value such as 5. In that case, above
expression will only set the first element to 5, rest will be zeros.

It's better to use `memset()` to be sure (?).

