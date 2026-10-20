/*
Write a C program that takes an integer from the user and determines whether
the number is even or odd.
*/

#include <stdio.h>

void odd_or_even(int *number)
{
    if(*number%2==0)
    {
        printf("The entered number is %d even.\n", *number);
    }
    else
    {
        printf("The entered number is %d odd.\n", *number);
    }

}

int main()
{
    printf("Enter a number: \n");
    int number = 0;
    scanf("%d", &number);
    odd_or_even(&number);
    printf("Program Completed.");
    return 0;
}
