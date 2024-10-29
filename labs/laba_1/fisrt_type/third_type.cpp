#pragma once
#include "everything.h"

void third() {
    char str[100];
    int length = 0;

    ifstream inputFile("input.txt");

    inputFile.getline(str, sizeof(str));
    while (str[length] != '\0') {
        length++;
    }
    inputFile.close();

    string result = convert(str, length);

    ofstream outputFile("result.txt");

    outputFile << result;
    outputFile.close();

}