/*
Write a C program to remove duplicate elements from a given array
(original order preserved, no sorting).
*/

#include <stdio.h>

/* Removes duplicates in place and returns the new size */
int remove_duplicate(int arr[], int size)
{
    int k = 0; /* number of unique elements found so far */

    for (int i = 0; i < size; i++)
    {
        int found = 0;

        /* check if arr[i] already exists among the unique elements */
        for (int j = 0; j < k; j++)
        {
            if (arr[i] == arr[j])
            {
                found = 1;
                break;
            }
        }

        /* keep it only if it is new */
        if (!found)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    return k; /* new size */
}

int main()
{
    int size = 0;

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

    printf("Before removing duplicates: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    size = remove_duplicate(arr, size);

    printf("\nAfter removing duplicates: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}