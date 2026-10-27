/*
Write a C program that rotates the elements of an array by n positions in a
specified direction.
arr[6] = {0, 1, 2, 3, 4, 5};
rotation = Right
n = 3
1: 5, 0, 1, 2, 3, 4
2: 4, 5, 0, 1, 2, 3
3: 3, 4, 5, 0, 1, 2

rotation = Left
n = 3
1: 1, 2, 3, 4, 5, 0
2: 2, 3, 4, 5, 0, 1
3: 3, 4, 5, 0, 1, 2
*/

#include <stdio.h>

void rotate(int arr[], int size, int n, char direction)
{
    if (direction == 'R')
    {
        for (int i = 0; i < n; i++)
        {
            int temp = arr[size - 1];
            for (int j = size - 1; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int temp = arr[0];
            for (int j = 0; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = temp;
        }
    }
}

int main()
{
    int size, n = 0;
    char direction;

    printf("Enter the Size of the Array: \n");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }
    int arr[size];

    printf("Enter the Direction, Either 'L' or 'R': \n");
    scanf(" %c", &direction);

    printf("Enter the number of elements to move in %c direction: \n", direction);
    scanf("%d", &n);
    n = n % size;

    printf("Enter the array elements: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    rotate(arr, size, n, direction);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}