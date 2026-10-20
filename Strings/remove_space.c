/*
Write a C program that takes a string from the user and replaces every
sequence of multiple consecutive spaces with a single space.
*/

#include <stdio.h>
#include <string.h>

// void removeSpace(char arr[])
// {
//     int write = 0, prev_space = 0;
//     // printf("Printed: %c", space);
//     for (int i = 0; arr[i] != '\0'; i++)
//     {
//         char ch = arr[i];
//         if (ch == ' ')
//         {
//             if (prev_space == 0)
//             {
//                 arr[write] = ch;
//                 write++;
//                 prev_space = 1;
//             }
//         }
//         else
//         {
//             arr[write] = ch;
//             write++;
//             prev_space = 0;
//         }
//     }
//     arr[write] = '\0';
// }

// int main()
// {
//     printf("Enter a string: \n");
//     char arr[100] = {0};
//     fgets(arr, sizeof(arr), stdin);
//     printf("The string before: %s\n", arr);
//     removeSpace(arr);
//     printf("The string after removed sequence of spaces: %s\n", arr);
//     return 0;
// }

#include <stdio.h>

void remove_spaces_shift(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == ' ')
        {
            // Shift all characters after i one position to the left
            for (int j = i; arr[j] != '\0'; j++)
            {
                arr[j] = arr[j + 1];
            }
            // Don't increment i — check the same position again
            i--;
        }
    }
}

int main()
{
    printf("Enter a string: \n");
    char arr[100] = {0};
    fgets(arr, sizeof(arr), stdin);

    printf("Before: %s\n", arr);
    remove_spaces_shift(arr);
    printf("After:  %s\n", arr);

    return 0;
}