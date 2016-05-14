# P3- Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2. 

# Motivation
* Learn about arrays and loops and functions, yay :+1:
* learn about `strpbrk()`

# Assumptions
* ASCII chars only

# Logic
```
my_strpbrk(in s1, in s2)
   src, k = 0
   for (src = 0; s1[src] != '\0'; src++) {
      for (k = 0; s2[k] != '\0'; k++) {
         if (s1[src] == s2[k]) return src; 
      }
   }
   return -1;
}
```


