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