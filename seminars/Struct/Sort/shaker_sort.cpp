#include "shaker_sort.h"

template<typename type>
void shaker_sort(type arr[], int size) {
	bool swapped = true;
	int start = 0;
	int end = size - 1;

	while (swapped) {

		for (int i = start; i < end; i++)
		{
			if (arr[i] > arr[i + 1]) {
				type tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}

		if (!swapped) break;
		
		swapped = false;
		end--;

		for (int i = end - 1; i >= start; i--)
		{
			if (arr[i] > arr[i + 1]) {
				type tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}

		start++;
	}
}
template void shaker_sort<int>(int[], int);
template void shaker_sort<double>(double[], int);