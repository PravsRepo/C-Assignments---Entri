/*
Write a C program that takes a string of digits from the user and converts it into
its equivalent integer value.
*/

#include <stdio.h>
int string_to_decimal(char number[])
{
    int temp = 0;
    for(int i=0; number[i]!='\0'; i++)
    {
        temp = temp * 10 + (number[i]-'0');
    }
    return temp;
}


int main()
{
    printf("Enter a string of digits: \n");
    char number[16];
    int result = 0;
    scanf("%s", number);
    result = string_to_decimal(number);
    printf("\nThe string is %s and the equivalent integer for the string is %d", number, result);
    return 0;
}