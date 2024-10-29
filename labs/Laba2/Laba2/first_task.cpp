#include "inc.h"


void first_task() {
    int length = 0;
    char symbol;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL) {
        cout << "Memory was not allocated" << endl;
        exit(1);
    }

    cout << "Enter message: ";

    while ((symbol = getchar()) != '\n') {
        str[length++] = symbol;

        char* tmp = (char*)malloc((length + 1) * sizeof(char));
        if (tmp == NULL) {
            cout << "Memory was not allocated for tmp" << endl;
            free(str);
            exit(1);
        }

        for (int i = 0; i < length; i++) {
            tmp[i] = str[i];
        }

        free(str);
        str = tmp;
    }

    string result = convert(str, length);
    free(str);
    cout << result << endl;
}