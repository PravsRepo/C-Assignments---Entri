/*
Write a C program that uses functions to convert a decimal number to any base
between 2 and 16.
*/
#include <stdio.h>

void anybase(int number, int base, int arr[], int *count)
{
    int remainder = 0;
    // Handle 0 separately
    if (number == 0)
    {
        arr[0] = 0;
        *count = 1;
        return;
    }

    while (number != 0)
    {
        remainder = number % base;
        arr[*count] = remainder;
        (*count)++;
        number = number / base;
        printf("%d %d %d\n", remainder, number, *count);
    }
    printf("Loop Ended! \n");
}

int main()
{
    printf("Enter a decimal number and the base: \n");
    int number = 0, base = 0, count = 0;
    int arr[32] = {0};
    scanf("%d %d", &number, &base);
    if (number > 1 && base >= 2)
    {
        anybase(number, base, arr, &count);

        printf("Base: %d, Number: %d \n", base, number);
        printf("The converted value is, ");
        for (int i = count - 1; i >= 0; i--) // ✅ Just print in reverse
        {
            if (arr[i] < 10)
                printf("%d", arr[i]);
            else
                printf("%c", 'A' + (arr[i] - 10)); // ✅ Handle 10-15
        }
    }
    else
    {
        printf("Invalid input! Number must be >= 0 and base must be 2-16.\n");
    }

    return 0;
}
