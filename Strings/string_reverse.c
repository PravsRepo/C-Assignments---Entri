/*
Write a C program that takes a string from the user and reverses its characters
using an iterative approach.
*/

#include <stdio.h>
#include <string.h>

void swap_char(char arr[])
{
    size_t length = strlen(arr);
    int left = 0;
    int right = length - 1;
    char temp = 0;

    while(left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
    
}

int main()
{
    printf("Enter a String: \n");
    char arr[16] = {0};
    scanf("%s", arr);
    printf("The String: %s \n", arr);
    swap_char(arr);
    printf("String Reversed: %s \n", arr);
    return 0;
}