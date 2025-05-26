#include <stdio.h>

#define BIT_TOGGLE(num, bit) ((num) ^ (1U << bit))

int main()
{
    printf("Toggling bit: %d of number: %d, output: %d", 1, 3, BIT_TOGGLE(3, 1));
    return 0;
}