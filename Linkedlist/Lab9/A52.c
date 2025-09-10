//  WAP to find the largest element in the array using Pointer.
#include<stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *largest = arr;
    for (int i = 1; i < n; i++)
    {
        if (*(arr + i) > *largest)
        {
            largest = arr + i;
        }
    }
    printf("The largest element in the array is: %d\n", *largest);
    return 0;
}