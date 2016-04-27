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

# Test run
```
Sankets-Mac-mini:P5 sanket$ make
make build
clang -g mywc.c -I.
make run
./a.out


elementary my dear watson
elementary!
lines: 2    words: 5    characters: 38
*** Copyright 2016 (C) Flying Coyote Software ***

Sankets-Mac-mini:P5 sanket$ a.out
bash: a.out: command not found
Sankets-Mac-mini:P5 sanket$ make run
./a.out



lines: 1    words: 0    characters: 1
*** Copyright 2016 (C) Flying Coyote Software ***

Sankets-Mac-mini:P5 sanket$ echo "this is a test" | ./a.out


lines: 1    words: 4    characters: 15
*** Copyright 2016 (C) Flying Coyote Software ***
```

## Additional exercise
Have a look at the BSD implementaion of wc [here](http://opensource.apple.com//source/text_cmds/text_cmds-84/wc/wc.c)

TODO - why is it so much longer and more complex?