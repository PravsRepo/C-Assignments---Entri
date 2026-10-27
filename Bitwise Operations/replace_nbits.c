/*
Write a C program that takes a number and replaces n of its bits, starting from
a given position, with another set of n bits from a second number.
*/

#include <stdio.h>

void print_binary(int num)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int replace_bits(int a, int b, int pos, int n)
{
    int mask = (1 << n) - 1;              // n ones
    int bits = ((b >> pos) & mask) << pos; // corresponding n bits from b, at pos
    a = a & ~(mask << pos);                // clear the hole in a
    return a | bits;                       // fill the hole
}

int main()
{
    int num1, num2, pos, n;

    printf("Enter the first number (num1): ");
    scanf("%d", &num1);

    printf("Enter the second number (num2): ");
    scanf("%d", &num2);

    printf("Enter the starting position: ");
    scanf("%d", &pos);

    printf("Enter the number of bits (n): ");
    scanf("%d", &n);

    // Validation
    if (pos < 0 || n <= 0 || pos + n > 32)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\nnum1 (before): ");
    print_binary(num1);
    printf("num2:          ");
    print_binary(num2);

    int result = replace_bits(num1, num2, pos, n);

    printf("\nnum1 (after):  ");
    print_binary(result);
    printf("Result: %d\n", result);

    return 0;
}

/*
mask = (1 << n) - 1
mask = (1 << n) = (1 << 2) = 0000 0100 = 4
mask = 4 - 1 = 3 = 0000 0011

bits = ((b >> pos) & mask) << pos;
b >> pos = 0000 1100 >> 1 = 0000 0110
(b >> pos) & mask = 0000 0110 & 0000 0011 = 0000 0010
((b >> pos) & mask << pos) = 0000 0010 << 1 = 0000 0100

a = a & ~(mask << pos)

mask << pos = 0000 0011 << 1 = 0000 0110
~(mask << pos) = 1111 1001
a & ~(mask << pos) = 0000 1010 & 1111 1001
a = 0000 1000

a = a | bits
a | bits = 0000 1000 | 0000 0100
a = 0000 1100
*/