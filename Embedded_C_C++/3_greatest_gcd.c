#include <stdio.h>

int main()
{
    int a = 20, b = 28, t;
    while (b)
    {
        t = b;
        b = a % b;
        a = t;
    }
    printf("%d", a);
    return 0;
}