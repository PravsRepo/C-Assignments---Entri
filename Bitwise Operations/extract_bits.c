/*
Write a C program that takes an integer from the user and extracts (n) bits
starting from a specific bit position.
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

int extract_bits(int num, int pos, int n)
{
    // Step 1: Shift the number right by pos
    num = num >> pos;
    printf("\nNumber in Binary: \n");
    print_binary(num);
    int mask = (1 << n) - 1;
    printf("Mask: \n");
    print_binary(mask);
    // Step 2: AND with (1 << n) - 1 to keep only n bits
    return (num & mask);
}

int main()
{
    int num, pos, n = 0;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the starting position: ");
    scanf("%d", &pos);

    printf("Enter the number of bits to extract: ");
    scanf("%d", &n);

    // Validation
    if (pos < 0 || n <= 0 || pos + n > 32)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("\nOriginal number:\n");
    printf("Decimal: %d\n", num);
    printf("Binary:  ");
    print_binary(num);

    int result = extract_bits(num, pos, n);

    printf("\nExtracted %d bit(s) starting at position %d:\n", n, pos);
    printf("Decimal: %d\n", result);
    printf("Binary:  ");
    print_binary(result);

    return 0;
}
