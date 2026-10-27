/*
Write a C program that merges two sorted arrays into a single sorted array
without using any sorting function.
*/
#include <stdio.h>

void sort_array(int arr[], int arr_size)
{
    int replace = 0;

    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = 0; j < arr_size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                replace = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = replace;
            }
        }
    }

    // printing the sorted array
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
}


void merge_array(int first_arr[], int second_arr[], int first_arr_size, int second_arr_size, int result_arr[])
{

    int i = 0, j = 0, k = 0;
    while (i < first_arr_size && j < second_arr_size)
    {
        /* code */
        if (first_arr[i] <= second_arr[j])
        {
            result_arr[k] = first_arr[i];
            i++;
        }
        else
        {
            result_arr[k] = second_arr[j];
            j++;
        }
        k++;
    }

    while (i < first_arr_size)
    {
        result_arr[k] = first_arr[i];
        i++;
        k++;
    }
    while (j < second_arr_size)
    {
        result_arr[k] = second_arr[j];
        j++;
        k++;
    }
}

int main()
{
    int first_arr_size = 0, second_arr_size = 0;

    printf("Enter the Size of the 1st Array: \n");
    scanf("%d", &first_arr_size);

    printf("Enter the Size of the 2nd Array: \n");
    scanf("%d", &second_arr_size);

    if (first_arr_size <= 0 && second_arr_size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int first_arr[first_arr_size], second_arr[second_arr_size];

    printf("Enter the 1st array elements: \n");
    for (int i = 0; i < first_arr_size; i++)
    {
        scanf("%d", &first_arr[i]);
    }

    printf("Enter the 2nd array elements: \n");
    for (int i = 0; i < second_arr_size; i++)
    {
        scanf("%d", &second_arr[i]);
    }

    int result_arr_size = first_arr_size + second_arr_size;
    int result_arr[result_arr_size];
    
    printf("First array Sorted: \n");
    sort_array(first_arr, first_arr_size);
    printf("\nSecond array Sorted: \n");
    sort_array(second_arr, second_arr_size);

    merge_array(first_arr, second_arr, first_arr_size, second_arr_size, result_arr);

    printf("\nArray Merged: \n");
    for (int i = 0; i < result_arr_size; i++)
    {
        printf("%d ", result_arr[i]);
    }
    return 0;
}