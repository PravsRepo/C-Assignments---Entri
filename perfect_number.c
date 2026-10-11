/*
Write a C program that uses a function to check whether a given number is a
Perfect Number.
*/

#include <stdio.h>

int perfect_num(int number)
{
    int divisor = 0, temp;
    divisor = number / 2;
    for(int i = 1; i <= divisor; i++)
    {
        if (number % i == 0)
        {
            temp = temp + i;
        }
    }
    return temp;
}

int main()
{
    printf("Enter a positive integer: \n");
    int number = 0, result = 0;
    scanf("%d", &number);
    result = perfect_num(number);
    if (number == result)
    {
        printf("The number %d is the perfect number.", number);
    }
    else
    {
        printf("The number %d is not the perfect number.", number);
    }
    return 0;
}