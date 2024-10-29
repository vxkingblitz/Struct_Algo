
template <typename type> void shell_sort(type array[], int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; i++) {
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                type temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
}


template void shell_sort<int>(int array[], int size);
template void shell_sort<double>(double array[], int size);

