#include "binary_insertion_sort.h"

template<typename type>
int binarySearch(type arr[], type item,int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

template<typename type>
void binary_insertion_sort(type arr[], int size)
{
    int location, j, k;

    for (int i = 1; i < size; ++i)
    {
        j = i - 1;
        type selected = arr[i];

        location = binarySearch(arr, selected, 0, j);

        while (j >= location)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}


template void binary_insertion_sort<int>(int[], int);
template void binary_insertion_sort<double>(double[], int);