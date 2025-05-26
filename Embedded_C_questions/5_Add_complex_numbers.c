#include <stdio.h>

struct Complex
{
    int real;
    int img;
};

struct Complex addComplex(struct Complex c1, struct Complex c2)
{
    struct Complex result = {.real = 0, .img = 0};
    result.real = c1.real + c2.real;
    result.img = c1.img + c2.img;

    return result;
}

int main()
{
    struct Complex c1, c2, result;
    c1.real = 10;
    c1.img = 2;

    c2.real = 20;
    c2.img = 3;

    result = addComplex(c1, c2);

    printf("Output of the addition of the two complex numbers: %d + %di", result.real, result.img);

    return 0;
}