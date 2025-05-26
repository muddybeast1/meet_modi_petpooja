#include <stdio.h>

void recursion(int num)
{
    switch (num)
    {
        default:
        printf("%d ", num++);
        recursion(num);
        case 1001:
            break;
    }
}

int main()
{
    recursion(1);
    return 0;
}