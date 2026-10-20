/*
Write a C program that takes a string input from the user and determines
whether it is a pangram or not.
*/

#include <stdio.h>
#include <string.h>

int is_pangram(char arr[])
{
    int seen[26] = {0};
    for (int i = 0; arr[i] != '\0'; i++)
    {
        char ch = arr[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }
        if (ch >= 'a' && ch <= 'z')
        {
            seen[ch - 'a'] = 1;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if(seen[i]==1)
        {
            count++;
        }
    }
    return (count==26);
}

int main()
{
    printf("Enter a sentence: \n");
    char arr[52] = {0};
    
    fgets(arr, sizeof(arr), stdin);

    if(is_pangram(arr))
    {
        printf("The entered string/sentence - %s \nIt is a pangram.", arr);
    }
    else
    {
        printf("The entered string/sentence - %s \nIt is not a pangram.", arr);
    }
    return 0;
}