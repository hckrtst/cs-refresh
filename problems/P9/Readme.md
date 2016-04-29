# P9 - Write htoi() - (K&R ex2.3)
In real life, you would use `strtol()`

# Motivation
* undersanding of hex and conversion of types

# Assumptions
* there can be spaces before the word, any trialing spaces chars are discarded
* can there be a sign?
* need to check for out of bounds errors

# Logic
```
int htoi(const string s) {
   if s is NULL ret 0;
   ptr p <-- s
   while (*p is space) {
      inc p
   }
   // skip 0x
   if "0x" or "0X' {
      inc p twice
   }

   // acc result one by one
   // note: shift left 4 is eq of mult by 16 and faster
   while (not NULL and not space) {
      if (can exceed MAXINT) 
         break
      acc <-- acc * base16 + getnextdigit   
   }
   return acc
}
```

# Reference
* http://opensource.apple.com//source/xnu/xnu-1456.1.26/bsd/libkern/strtol.c
