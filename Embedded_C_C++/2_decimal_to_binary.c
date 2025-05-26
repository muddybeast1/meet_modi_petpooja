#include <stdio.h>

int main()
{
    int n = 545, i, b[32];
    for (i = 0; n > 0; i++)
    {
        b[i] = n % 2;
        n /= 2;
    }
    for (i = i - 1; i >= 0; i--)
        printf("%d", b[i]);
    return 0;
}