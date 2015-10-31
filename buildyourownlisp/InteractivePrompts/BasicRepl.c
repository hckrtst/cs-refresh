#include <stdio.h>

#define INPUT_BUFFER_LEN 48
// Declare this as static so as to avoid name collision
// if we link this with another module
static char input_buf[INPUT_BUFFER_LEN];

int main(int argc, char** argv)
{
  puts("** Welcome to Kitty\'s playground\n");
  puts("Press Ctrl + c to exit\n");

  while(1) {
    fputs("kitty> ", stdout);
    fgets(input_buf, INPUT_BUFFER_LEN, stdin);
    printf("Meow meow %s", input_buf);
  }
}
