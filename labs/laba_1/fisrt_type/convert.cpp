#pragma once
#include "everything.h"

using namespace std;

string convert(char str[], int length) {
    string result = "";
    int count = 0;
    int countSpace = 0;
    int arr[100] = {};

    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ') {
            count++;
            countSpace++;
        }
        else {
            if (countSpace > 4) {
                for (int j = 0; j < countSpace; j++)
                {
                    result += '_';
                }
            }
            countSpace = 0;
            result += str[i];
        }


    }

    return result;

}