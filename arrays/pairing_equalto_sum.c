/*
Write a C program that finds all pairs of elements in an array whose sum equals
a given target value.
*/

#include <stdio.h>
void pairing_matches(int arr[], int size, int sum)
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((arr[i] + arr[j]) == sum)
            {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;     
            }
        }
    }

    if (!found)
    {
        printf("No pair found with sum %d \n", sum);
    }
}

int main()
{
    printf("Enter the Size of the Array: \n");
    int size = 0, sum = 0;
    scanf("%d", &size);
    int arr[size];

    if (size <= 0)
    {
        printf("Invalid Size! \n");
        return 1;
    }

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the Target Sum: \n");
    scanf("%d", &sum);

    pairing_matches(arr, size, sum);

    return 0;
}