# P6 - Write your own strlen() - (K&R 2.3)

# Approach
```
int strlen(const char *s)
    ptr p <- s
    while (content of s not'\0')
        inc p
    dec p    
    return (s - p)    

```

# Real implementations
* http://opensource.apple.com//source/Libc/Libc-167/gen.subproj/i386.subproj/strlen.c
* http://opensource.apple.com/source/Libc/Libc-498.1.1/i386/string/strlen.s