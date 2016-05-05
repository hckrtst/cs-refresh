# P10 Write a clone of `strcat()`

# Motivation
An exercise in incrementing succintly

# Pseudocode
```
strcat(char target[], char src[])
{
   // todo null check target and str

   // first we find the end of target
   i,j = 0
   while (target[i] is not NULL) {
      inc i
   }

   while(copied char is not NUL) {
      target[i] = src[j]
      inc i,j
   }
}


# Caution
`strcat()` is not a safe function. `strlcat()` may be a [safer alternative](http://www.sudo.ws/todd/papers/strlcpy.html). Even the [US govt](https://buildsecurityin.us-cert.gov/articles/knowledge/coding-practices/openbsd-strlcpy-and-strlcat) advises against `strcat()`.

Interestingly enough, the openbsd implementation of `strcat()` comes with a stern warning to use `strlcat()`.

:+1: Good on them

```
#if defined(APIWARN)
__warn_references(strcat,
    "warning: strcat() is almost always misused, please use strlcat()");
#endif

``````

Here is an example of the stack getting smashed when we overflow the buffer. Check the `argc` and `argv`.
```
(lldb) print mystr
(char *) $1 = 0x6d6c6b6a69686766 ""
(lldb) print mystr2
(char [5]) $2 = "abcdefghijklmnopqrstuvwxyzsdjskdjdkjdksdjskdjdksjdksjdskdjskdjskjskdjskdjskjskjskjd"
(lldb) s
Output = abcdefghijklmnopqrstuvwxyzsdjskdjdkjdksdjskdjdksjdksjdskdjskdjskjskdjskdjskjskjskjd
Process 12150 stopped
* thread #1: tid = 12150, 0x0000000000400637 p10`main(argc=2037938038, argv=0x7574737271706f6e) + 199 at p10.c:46, name = 'p10', stop reason = step in
    frame #0: 0x0000000000400637 p10`main(argc=2037938038, argv=0x7574737271706f6e) + 199 at p10.c:46
   43
   44
   45
-> 46        return 0;
   47    }
(lldb) s
Process 12150 stopped
* thread #1: tid = 12150, 0x0000000000400641 p10`main(argc=<unavailable>, argv=<unavailable>) + 209 at p10.c:46, name = 'p10', stop reason = signal SIGSEGV: invalid address (fault address: 0x0)
    frame #0: 0x0000000000400641 p10`main(argc=<unavailable>, argv=<unavailable>) + 209 at p10.c:46
   43
   44
   45
-> 46        return 0;
   47    }

```

# Bonus
Let's also write `strlcat()`

# Pseudocode
```
strlcat(char target[], char src[], int size)
{
   i,j = 0
   while(target[i] is not NUL and i < size) {
      inc i
   }

   while(copied char not NUL and i < size) {
      target[i] = src[j]
      inc i,j
   }

   target[i] = '\0'
   ret num of chars copied excluding NUL
}
```

# Resources
* [OpenBSD implementation](http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/lib/libc/string/strlcat.c)