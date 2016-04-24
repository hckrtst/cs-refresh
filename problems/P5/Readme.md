# P5 - Write your own version of wc (K&R C 1.5.4)
Here is a unix program called `wc`. This is what it does:
```
Sankets-Mac-mini:cs-refresh sanket$ echo "island in the sun" | wc
       1       4      18

Sankets-Mac-mini:cs-refresh sanket$ wc
1234
789
       2       2      10
```
Shows 1 line, 4 words and 18 characters
Write it from scratch.

# Assumptions
* All input is ascii chars
* We parse the words char by char in loop

# Method
* We count each char (space, new line etc as a char)
* find the word boundaries to count words

## Basic pseudoCode
```
    isWord = false
    while (c is not EOF)
        inc char count
        if (c is space or newline or tab)
            // we were originally in a word
            if (isWord is true)
                inc word count
                isWord = false
            end
            if (c is newline)
                inc newline count
            end
        else
            if (isWord is false)
                isWord = true
        end
        read next c
    end
```