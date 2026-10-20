/*
 Write a C program that takes a string from the user and checks whether it is a
palindrome.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void palindrome(char arr_str[], bool *flag)
{
    size_t length = strlen(arr_str);
    printf("Length is %zu \n", length);
    for (int i = 0; i < length; i++)
    {
        // printf("%c %c \n", arr_str[i], arr_str[length-1]);
        // length--;
        if (arr_str[i] != arr_str[length - 1])
        {
            *flag = false;
            return;
        }
        length--;
    }
}

int main()
{
    printf("Enter a String: \n");
    bool flag = true;
    char arr_str[20] = {0};
    scanf("%s", arr_str);
    // printf("The entered string is, %s \n", arr_str);
    palindrome(arr_str, &flag);

    if(flag)
    {
        printf("The string %s is palindrome.", arr_str);
    }
    else
    {
        printf("The string %s is not palindrome.", arr_str);
    }
    return 0;
}