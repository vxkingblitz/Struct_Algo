#pragma once
#include "everything.h"

void first() {
    int n = 0;
    char str[100];
    char tmp;
    cout << "Enter message: ";
    tmp = getchar();
    while (tmp != '\n') {
        str[n] = tmp;
        n++;
        tmp = getchar();
    }
    string result = convert(str, n);
    cout << result << endl;
}