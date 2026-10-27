/*
Write a C program that rearranges an array such that all negative numbers
appear before all positive numbers while preserving the relative order of both
groups.
*/

#include <stdio.h>
void sort_wo_changing_order(int arr[], int size)
{
    int positive_arr[size];

    int neg_element = 0, element = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            arr[neg_element] = arr[i];
            neg_element++;
        }
        else
        {
            positive_arr[element] = arr[i];
            element++;
        }
    }

    int k = 0;
    for (int i = neg_element; i < size; i++)
    {
        arr[i] = positive_arr[k];
        k++;
    }
}

int main()
{
    printf("Enter the Size of the Array: \n");
    int size = 0;
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

    sort_wo_changing_order(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}