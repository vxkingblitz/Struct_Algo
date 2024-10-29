#pragma once
#include "everything.h"


void second() {
	char str[100];
	cout << "Enter message: ";
	fgets(str, sizeof(str), stdin);
	int n = strlen(str);
	string result = convert(str, n);
	cout << result << endl;
}