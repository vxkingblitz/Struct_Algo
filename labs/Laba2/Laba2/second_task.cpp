#include "inc.h"


void second_task() {
	int length = 0, allocated = 4;
	char symbol;
	char* str = (char*)calloc(allocated, sizeof(char));

	if (str == NULL) {
		cout << "Memory was not allocated" << endl;
		exit(1);
	}

	cout << "Enter message: ";
	
	while ((symbol = getchar()) != '\n') {
		if (length >= allocated) {
			allocated += 4;
			char* tmp = (char*)realloc(str, allocated * sizeof(char));
			
			if (tmp != NULL) {
				str = tmp;
			}
			else {
				free(str);
				cout << "Memory was not allocated for tmp" << endl;
				exit(1);
			}
		}

		str[length++] = symbol;
	}


	string result = convert(str, length);
	free(str);
	cout << result << endl;

}