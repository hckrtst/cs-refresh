#include "utils.h"

// setting to 1 so that we can generate more, don't init to 0
static unsigned long int next = 1;

void my_srand(const unsigned int seed) {
    next = seed;
}

int my_rand(void) {
    next = next * 11345697354 + 856375;
    return (unsigned int)(next / 634523) % 32768;
}