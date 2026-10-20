/*
Write a C program to generate the Fibonacci series up to a given number of terms.
*/

#include <stdio.h>

void fibonacci(int *num)
{
    if (*num == 1)
    {
        printf("0\n");
        return;
    }

    int temp = 0, temp_1 = 1, result = 0;

    printf("%d", temp);
    for (int i = 1; i < *num; i++)
    {
        result = temp + temp_1;
        temp_1 = temp;
        temp = result;
        printf(", %d", temp);
    }
    printf("\n");
}

int main()
{
    int num = 0;
    printf("Enter a positive integer: \n");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Please enter a positive number.\n");
        return 0;
    }

    fibonacci(&num);
    return 0;
}
