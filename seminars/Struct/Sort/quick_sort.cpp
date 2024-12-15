template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            
        }
    }
    T tmp = arr[i + 1];
    arr[i+1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

template <typename T>
void quick_sort(T arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

template void quick_sort<int>(int[], int, int);
template void quick_sort<double>(double[], int, int);