/*
Write a C program that uses a recursive function to find the GCD of two
numbers using the Euclidean algorithm.
*/

#include <stdio.h>

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a % b);
}


int main()
{
    printf("Enter two positive integers: \n");
    int a = 0, b = 0, result = 0;
    scanf("%d %d", &a, &b);

    result = gcd(a, b);

    printf("The GCD is %d", result);
    return 0;
}