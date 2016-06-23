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

