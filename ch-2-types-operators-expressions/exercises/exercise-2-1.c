#include <stdio.h>
#include <limits.h>

void printMaxAndMin(const char *type, unsigned long max, long min);

/* determines the ranges of char, short, int, and long,
    both signed and unsigned, by use of headers and direct computation */
int main(void)
{
    printf("Using Headers\n");
    printMaxAndMin("char", SCHAR_MAX, SCHAR_MIN);
    printMaxAndMin("unsigned char", UCHAR_MAX, 0);
    printMaxAndMin("short", SHRT_MAX, SHRT_MIN);
    printMaxAndMin("unsigned short", USHRT_MAX, 0);
    printMaxAndMin("int", INT_MAX, INT_MIN);
    printMaxAndMin("unsigned int", UINT_MAX, 0);
    printMaxAndMin("long", LONG_MAX, LONG_MIN);
    printMaxAndMin("unsigned long", ULONG_MAX, 0);

    printf("\nUsing Direct Computation\n");
    char signedCharMax = 0, signedCharMin = 0;
    unsigned char unsignedCharMax = 0;

    while (signedCharMax <= 0)
        signedCharMax--;

    while (signedCharMin >= 0)
        signedCharMin++;

    printMaxAndMin("char", signedCharMax, signedCharMin);
    printMaxAndMin("unsigned char", --unsignedCharMax, 0);

    short signedShortMax = 0, signedShortMin = 0;
    unsigned short unsignedShortMax = 0;

    while (signedShortMax <= 0)
        signedShortMax--;

    while (signedShortMin >= 0)
        signedShortMin++;

    printMaxAndMin("short", signedShortMax, signedShortMin);
    printMaxAndMin("unsigned short", --unsignedShortMax, 0);

    int signedIntMax = 0, signedIntMin = 0;
    unsigned int unsignedIntMax = 0;

    while (signedIntMax <= 0)
        signedIntMax--;

    while (signedIntMin >= 0)
        signedIntMin++;

    printMaxAndMin("int", signedIntMax, signedIntMin);
    printMaxAndMin("unsigned int", --unsignedIntMax, 0);

    // warning: a signed long can hold a number larger than 9 quintillion!
    long signedLongMax = 0, signedLongMin = 0;
    unsigned long unsignedLongMax = 0;

    while (signedLongMax <= 0)
        signedLongMax--;

    while (signedLongMin >= 0)
        signedLongMin++;

    printMaxAndMin("long", signedLongMax, signedLongMin);
    printMaxAndMin("unsigned long", --unsignedLongMax, 0);

    return 0;
}

void printMaxAndMin(const char *type, unsigned long max, long min)
{
    printf("%s\n", type);
    printf("max = %lu\n", max);
    printf("min = %ld\n", min);
}
