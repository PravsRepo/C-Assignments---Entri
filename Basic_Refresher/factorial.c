/*
Write a C program that takes a positive integer from the user and calculates its
factorial.
*/

#include <stdio.h>
unsigned long long factorial(int num)
{
    unsigned long long fact = 1;
    for(int i=1; i<=num; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int num = 0;
    unsigned long long result = 0;
    do{
        printf("Enter a Positive Integer: \n");
        scanf("%d", &num);

        if(num<0)
        {
            printf("Invalid input. Please enter a positive number.\n");
        }
    }while(num<0);
   
    result = factorial(num);
    printf("The factorial of %d is %llu", num, result);
    return 0;
}
