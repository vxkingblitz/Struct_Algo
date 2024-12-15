#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void merge_sort(const string& filename) {
    int blockSize = 1; 
    ifstream f;
    ofstream f1, f2;

    vector<int> data;
    int value;
    f.open(filename);
    while (f >> value) {
        data.push_back(value);
    }
    f.close();

    int totalElements = data.size();

    while (blockSize < totalElements) {
        f.open(filename);
        f1.open("f1");
        f2.open("f2");

        int count = 0;
        while (f >> value) {
            if ((count / blockSize) % 2 == 0) {
                f1 << value << " ";
            }
            else {
                f2 << value << " ";
            }
            count++;
        }

        f.close();
        f1.close();
        f2.close();

        ofstream output(filename);
        ifstream f1("f1"), f2("f2");

        int left, right;
        bool hasLeft = static_cast<bool>(f1 >> left); // check if has smt in file
        bool hasRight = static_cast<bool>(f2 >> right);

        while (hasLeft || hasRight) {
            int i = 0, j = 0;
            while (i < blockSize && j < blockSize && hasLeft && hasRight) {
                if (left <= right) {
                    output << left << " ";
                    hasLeft = static_cast<bool>(f1 >> left);
                    i++;
                }
                else {
                    output << right << " ";
                    hasRight = static_cast<bool>(f2 >> right);
                    j++;
                }
            }
            while (i < blockSize && hasLeft) {
                output << left << " ";
                hasLeft = static_cast<bool>(f1 >> left);
                i++;
            }
            while (j < blockSize && hasRight) {
                output << right << " ";
                hasRight = static_cast<bool>(f2 >> right);
                j++;
            }
        }

        output.close();
        f1.close();
        f2.close();

        blockSize *= 2;
    }

    remove("f1");
    remove("f2");
}


