# What is this?
Notes and accompanying examples by topic.

# Concurrency

* Concurency accomplished with Threads in Java. 

* We can do this two ways

1. Provide a runnable object which implements `Runnable`

 ```java
 public class HelloRunnable implements Runnable {

    public void run() {
        System.out.println("Hello from a thread!");
    }

    public static void main(String args[]) {
        (new Thread(new HelloRunnable())).start();
    }

 }
 ```
This is preferred way of starting threads as it is more general. Now our class can extend something else! :ok_hand: 	

2. Subclass `Thread`

Alternatively, we can just subclass it like so, however the first idiom is more flexible.
```java
public class HelloThread extends Thread {

    public void run() {
        System.out.println("Hello from a thread!");
    }

    public static void main(String args[]) {
        (new HelloThread()).start();
    }

}
```
## Examples

### BuggyConcurrency

In this example, we look at a common producer and consumer problem. Both producer and consumer are running in two distinct threads.
The producer is producing random integers and filling a fixed size buffer. 

We don't use any synchronization on purpose so we can see what kind of issues we may encounter.


### References
* http://www.cs.umd.edu/~pugh/java/memoryModel/jsr-133-faq.html


### ShoddyConcurrency
TBD

### ConcurrencyWithWaitNotify 
TBD

### Dinining Philosophers
TBD

# Arrays and Strings

## Reversing strings

# Interger Overflows
* The type int is a signed 32-bit integer and the type long is a 64-bit integer. A Java program does not recognize an integer overflow and the program continues with wrong results
* C also does not handle overflows :grimacing:
* clang has an option to check overflow exceptions
```
-ftrapv
          Generate code to catch integer overflow errors.  Signed integer overflow is unde-
          fined in C. With this flag, extra code is generated to detect this and abort when
          it happens.
```

## Reference
* http://rosettacode.org/wiki/Integer_overflow

# Trees
TBD

# Linked Lists
TBD

## Problems
TBD

## A basic list structure

1. Push item

2. Pop item

3. Reverse list

# Bit manipulations

## Resources
* https://www.scribd.com/doc/310278949/Hacker-s-Delight

## References
* http://cglab.ca/~abeinges/blah/too-many-lists/book/README.html
* http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
* http://cslibrary.stanford.edu/102/PointersAndMemory.pdf