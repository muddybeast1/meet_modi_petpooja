#include <stdio.h>

#define MIN(a, b) (a < b)?a:b 

int main()
{
    printf("Min: %d\n", MIN(10, 11));
    return 0;
}