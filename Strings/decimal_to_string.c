/*
Write a C program that takes an integer from the user and converts it into a
string of characters.
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

void int_to_string(int number, char str[])
{
    int i = 0;

    // Handle zero
    if (number == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    // Handle negatives
    if (number < 0)
    {
        str[i] = '-';
        i++;
        number = -number;
    }

    while (number > 0)
    {
        str[i] = (number % 10) + '0';
        number = number / 10;
        i++;
    }
    str[i] = '\0';
    int start = (str[0] == '-') ? 1 : 0; // Skip '-' if present
    int end = i - 1;

    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    printf("Enter an Integer: \n");
    int number = 0;
    char str[16] = {0};
    scanf("%d", &number);

    int_to_string(number, str);
    printf("The integer as a string is: %s\n", str);
    return 0;
}