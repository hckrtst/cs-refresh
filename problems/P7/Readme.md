# P7 - Write a program that accepts several lines and identifies the longest one (K&R 1.9)

# Algorithm
```
while (input is not EOF) {
    newline = readline()
    if (line does not exist or (line exists and len(newline) > len(line)) {
        line = newline
        update len(line)
    }
}
print line
```