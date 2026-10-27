/*
Write a C program that uses an array to find the second largest and second
smallest element in a list of numbers.
*/

#include <stdio.h>
#include <limits.h>
void find_appropriate(int arr[], int size)
{
    int large = arr[0], second_large = INT_MIN;
    int small = arr[0], second_small = INT_MAX;

    for (int i = 1; i < size; i++)
    {
        if (large < arr[i])
        {
            second_large = large;
            large = arr[i];
        }
        else if (arr[i] < large && arr[i] > second_large)
        {
            second_large = arr[i];
        }
        
        if (small > arr[i])
        {
            second_small = small;
            small = arr[i];
        }
        else if (arr[i] > small && arr[i] < second_small)
        {
            second_small = arr[i];
        }
    }
    if (second_small==INT_MAX && second_large == INT_MIN)
    {
        printf("All the elements are same.");
        return;
    }

    printf("%d %d", second_large, second_small);
}

int main()
{
    int size;

    printf("Enter the Size of the Array: \n");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[size];
    printf("Enter the array elements: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    find_appropriate(arr, size);

    return 0;
}