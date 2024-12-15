#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void merge_one_phase_sort(const string& filename) {
    int blockSize = 1;

    vector<int> data;
    int value;

    // Чтение данных из файла в вектор
    ifstream input(filename);
    while (input >> value) {
        data.push_back(value);
    }
    input.close();

    int totalElements = data.size();

    // Однофазная сортировка слиянием
    while (blockSize < totalElements) {
        vector<int> temp(totalElements);
        int leftStart = 0;

        while (leftStart < totalElements) {
            int mid = min(leftStart + blockSize, totalElements);
            int rightEnd = min(leftStart + 2 * blockSize, totalElements);

            int i = leftStart, j = mid, k = leftStart;

            // Слияние двух блоков
            while (i < mid && j < rightEnd) {
                if (data[i] <= data[j]) {
                    temp[k++] = data[i++];
                }
                else {
                    temp[k++] = data[j++];
                }
            }

            // Копирование оставшихся элементов из первого блока
            while (i < mid) {
                temp[k++] = data[i++];
            }

            // Копирование оставшихся элементов из второго блока
            while (j < rightEnd) {
                temp[k++] = data[j++];
            }

            leftStart += 2 * blockSize;
        }

        // Копирование временного массива обратно в основной
        data = temp;
        blockSize *= 2;
    }

    // Запись отсортированных данных обратно в файл
    ofstream output(filename);
    for (const auto& val : data) {
        output << val << " ";
    }
    output.close();
}


