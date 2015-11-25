// compile with cpp not with gcc
 
#define foo bar
#define bar 1010

foo

#include "test.h"

#define macro (array[(x = y, x + 1)])

macro(e, c)

macro

#define name(x) x,"-san"

name("hiroshi")


//concatenation

#define f(A,B) A##B

f(2,3)

// variadic macros
#define eprintf(format, ...) printf(stderr, format, ##__VA_ARGS__)
eprintf("%s %s", "test1", "test2\n");
eprintf("hello macros\n");

__DATE__
__TIME__
__FILE__
__unix__
