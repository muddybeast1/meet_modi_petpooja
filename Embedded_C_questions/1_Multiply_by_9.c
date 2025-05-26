#include <stdio.h>

int multiplyByNine(int num)
{
    int result;
    result = (num<<3) + num;
    return result;
}

int main()
{
    int num = 3;
    printf("%d multiplied by 9: %d", num, multiplyByNine(num));
    return 0;
}