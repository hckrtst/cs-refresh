# C Refresher

## Strings

* When a string is allocated on stack like so, it is not modifiable. Trying to do will throw a nasty run time access error :-1:

```c
char *s1 = "This cannot be modified";
```
* strlen will work for above string since it is statically allocated

* If string allocated like this, then it can be modified.

```c
char s2[] = "This can be modified";
```

# Resources
* http://c-faq.com/index.html
* ftp://ftp.idsoftware.com/idstuff/ (learn to code by reading code...now that's a novel idea eh!)
* Expert C programming: Deep C secrets (humorous and deep)
* K & R C (classic)
* http://c.learncodethehardway.org/book/ (opinionated and encourages lots of good practices)
