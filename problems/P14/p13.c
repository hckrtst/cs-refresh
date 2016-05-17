#include<stdio.h>
#include<assert.h>

int getbits(unsigned x, unsigned int p, unsigned int n) {
   return ((x >> (p - n +1)) & ~(~0 << n));
}
int main(int argc, char * argv[]) {
   unsigned x = 0b10001101101; 
   printf("Input = %p, output = %p\n", x, getbits(x, 5, 4));

   return 0;
}
