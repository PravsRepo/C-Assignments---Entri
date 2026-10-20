/*
Write a C program that uses a function to count the frequency of each digit (0–9)
in a given integer.
*/

#include <stdio.h>

void count_freq(int *num, int count[])
{
    int temp = *num, digit = 0;
    while(temp>0)
    {
        digit = temp % 10;
        temp = temp/10;
        count[digit]++;
    }
    // for(int i=0; i<10; i++)
    // {
    //     printf("%d", count[i]);
    // }
}

int main()
{
    printf("Enter an Integer: \n");
    int num = 0, count[10] = {0};
    scanf("%d", &num);
    count_freq(&num, count);
    for (int i = 0; i < 10; i++)
    {
        if (count[i] > 0)
        {
            printf("The digit %d appears %d time(s)\n", i, count[i]);
        }
    }
    return 0;
}