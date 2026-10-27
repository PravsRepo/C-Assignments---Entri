/*
Write a C program that takes two integers and swaps n bits starting from a given
position in both numbers
*/

#include <stdio.h>

void print_binary(int num)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

void replace_bits(int num1, int num2, int pos, int n)
{
    int mask = (1 << n) - 1;

    // Step 1: Extract bits BEFORE clearing
    int num1_bits = (num1 >> pos) & mask;
    int num2_bits = (num2 >> pos) & mask;

    // Step 2: Clear the target bits in both numbers
    num1 = num1 & ~(mask << pos);
    num2 = num2 & ~(mask << pos);

    // Step 3: Insert swapped bits
    num1 = num1 | (num2_bits << pos);
    num2 = num2 | (num1_bits << pos);

    printf("\nAfter swap:\n");
    printf("num1: ");
    print_binary(num1);
    printf("num2: ");
    print_binary(num2);
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
    printf("num2: ");
    print_binary(num2);

    replace_bits(num1, num2, pos, n);

    return 0;
}