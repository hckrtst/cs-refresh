# Telephone words

Fiven a telephone number find all combinations of letters.
Input is an array of seven digits. Use a method `get_char(int key, int place)`.
The place is 1, 2 or 3 and represents that particular character.


# Recursive approach
```
void print_tel_word(cur_digit, nums[], result) {
   if (cur_digit > sizeof nums) {
      print(result)
      return
   }
   for (i = 1; i <= 3; i++) {
      result[cur_digit] = get_char(cur_digit, i)
      print_tel_word(cur_digit + 1, nums,  result)
      if (num[cur_digit] == 0 or 1) return
   }
}
```

# Non-recursive approach

Example:
if we have a 3 digit number each digit can have A/B/C, D/E/F, X/Y/Z respectively
then we would have the following permutations:

```
ADX
ADY
ADZ
AEX
AEY
AEZ
AFX
AFY
AFZ
BDX
...
```

We can observe that we rotate each place in the sequence and when it reaches the end we also increment the next place by 1.

```
print_tel_word(nums[]) {
   char res[MAX_LENGTH] = {0}
   for (i = 0; i < sizeof(nums); i++) {
      print(get_char(nums[i], 1))
   }
   while (true) {
      for (i = sizeof(nums) - 1; i > -1; i--) {
         if (res[i] == get_char())
      }
   }
}
```