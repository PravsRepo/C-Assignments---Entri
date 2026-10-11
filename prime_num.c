/*
Write a C program that asks the user to enter a number and determines whether that
number is prime or not.
*/

#include <stdio.h>
#include <stdbool.h>

bool prime_num(int num)
{
    if(num<=1) return false;
    if(num==2) return true;
    if(num%2==0) return false;
   
    for(int i=3; i<=num/2; i+=2)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;

}

int main()
{
    printf("Enter a number: \n");
    int num=0;
    bool is_prime, result;
    scanf("%d", &num);
    result = prime_num(num);

    if(result)
    {
        printf("The number %d is prime.\n", num);
    }
    else{
        printf("The number %d is not prime.\n", num);
    }
    return 0;
}