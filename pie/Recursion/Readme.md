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