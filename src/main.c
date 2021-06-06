#include <stdio.h>
#define BIT_NINE 256
#define BIAS 127
#define MASK_31_BITS 8388607

int main(void)
{

    float number = 2.0;

    unsigned int binary = *(int *)&number;
    unsigned int signbit = binary >> 31;

    signed int exponent = (signed int)(((binary >> 23) - BIT_NINE * signbit) - BIAS);

    unsigned int mantissa = (binary & MASK_31_BITS);
    int counter = 2;
    double decimalSum = 0;
    int currentBit = 4194304;
    for (int i = 1; i <= 23; ++i)
    {
        if (mantissa / currentBit)
        {
            decimalSum += (1 / (double)counter);
            mantissa -= currentBit;
        }
        counter *= 2;

        currentBit = currentBit >> 1;
    }
    decimalSum += 1;
    printf("%f is represented in binary scientific notation as:\n", number);
    if (signbit)
        printf("-");
    printf("%.23f x 2^%d\n", decimalSum, exponent);

    return 0;
}