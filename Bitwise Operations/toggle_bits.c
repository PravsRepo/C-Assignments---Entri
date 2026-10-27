/*
Write a C program that takes a number and toggles a specific number of bits (n)
starting from a given position.
*/

#include <stdio.h>

void print_binary(int num)
{
    for (int i = 8; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); 
    }
    printf("\n");
}

int toggle_bits(int num, int pos, int n)
{
    int mask = (1 << n) - 1;

    mask = mask << pos;

    return num ^ mask;
}


int main()
{
    int num, pos, n = 0;
    printf("Enter the number:\n");
    scanf("%d", &num);

    printf("Enter the start position:\n");
    scanf("%d", &pos);

    printf("Enter the number of bits to toggle:\n");
    scanf("%d", &n);

    if (pos < 0 || n <= 0 || pos+n > 32)
    {
        printf("Invalid Input!\n");
        return 0;
    }

    printf("\nBefore toggling:\n");
    printf("Decimal: %d\n", num);
    printf("Binary:  ");
    print_binary(num);

    int result = toggle_bits(num, pos, n);

    printf("\nAfter toggling %d bit(s) starting at position %d:\n", n, pos);
    printf("Decimal: %d\n", result);
    printf("Binary:  ");
    print_binary(result);

    return 0;
}