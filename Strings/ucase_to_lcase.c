/*
Write a C program that takes a string from the user and converts all uppercase
letters into their corresponding lowercase letters.
*/

#include <stdio.h>

void to_lowercase(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        char ch = arr[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
            arr[i] = ch;
        }
        else
        {
            arr[i] = ch;
        }
    }
}

int main()
{
    printf("Enter a string: \n");
    char arr[100] = {0};
    fgets(arr, sizeof(arr), stdin);

    printf("Before: %s\n", arr);
    to_lowercase(arr);
    printf("After: %s\n", arr);

    return 0;
}