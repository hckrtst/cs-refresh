# P2 - Removing specified characters from a given array (K&R sec 2.8)
Design an algorithm to remove a specified char from an array. No extra buffer may be used.

# Motivation
* Arrays and pointer usage

# Assumptions
* Removing only specified char
* ascii chars

# Logic
```
/*
   we use a src and dest index
   when we encounter char c we skip over it
   otherwise we copy
*/
strip_chars(char []s, char c) {
   int src, dest
   for(src = dest = 0; s[src] is not NULL; inc src) {
      if (s[src] is not c) {
         s[dest] = s[src]
         inc dest
      }
   }
   s[dest] = NULL
}

```
