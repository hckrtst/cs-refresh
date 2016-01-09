/*
 * main.c
 * Copyright (C) 2016 Unknown <tintin@daredevil>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int reverse(int x) {
    int res = 0;
    int *digits = (int*) calloc(1024, sizeof(int));
    int holder = abs(x);
    int index = 0;
    
    while((holder >= 10)) {
        int new_holder = holder/10;
        int temp = holder - (new_holder*10);
        holder = new_holder;
        digits[index] = temp;
        printf("%d --> holder=%d \n", digits[index], holder);
        index++;
    }

    // last digit
    digits[index] = holder;

    int c = index;
    int i;
    for(i = 0; i <= c; i++) {
        printf("Res = %d, index = %d, pow = %d \n",
               res, i, (int) (pow(10,index)));
        int p = (int) pow(10,index);
        int t = digits[i] * p;
	    
       
        //handle overflow
        //goto yikes!
        if (t&& (t < p)) {
            res = 0;
            goto bail;
        }

        res = res + t;
        index--;
    }
bail:
    free(digits);
    digits = 0;
    if (x < 0) res*=-1;
    
    return res;
    
}

int main()
{
    int input;
    input = 34456;
    printf("input= %d  outcome = %d\n", input, reverse(input));
/*
    input = 319000;
    printf("input= %d  outcome = %d\n", input, reverse(input));

    input = -319000;
    printf("input= %d  outcome = %d\n", input, reverse(input));

    input = 20;
    printf("input= %d  outcome = %d\n", input, reverse(input));

    input = 10;
    printf("input= %d  outcome = %d\n", input, reverse(input));

    input = -10;
    printf("input= %d  outcome = %d\n", input, reverse(input));

    input = 0;
    printf("input= %d  outcome = %d\n", input, reverse(input));*/

	input = 100;
	printf("input= %d  outcome = %d\n\n", input, reverse(input));
	
	input = 1534236469;
	printf("input= %d  outcome = %d\n\n", input, reverse(input));
	
	input = 1563847412;
	printf("input= %d  outcome = %d\n\n", input, reverse(input));

    return 0;
}

