#include "inc.h"

void third_task() {
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
	
	ofstream outputFile("inp.txt");
	for (int i = 0; i < length; i++)
	{
		outputFile.put(str[i]);
	}
	
	free(str);
	outputFile.close();

	length = 0, allocated = 4;

	ifstream inputFile("inp.txt");
	char* new_str = (char*)calloc(allocated, sizeof(char));
	char new_sym;
	if (new_str == NULL) {
		cout << "Memory was not allocated" << endl;
		exit(1);
	}
	while (inputFile.get(new_sym)) {
		if (length >= allocated) {
			allocated += 4;
			char* tmp = (char*)realloc(new_str, allocated * sizeof(char));
			if (tmp != NULL) {
				new_str = tmp;
			}
			else {
				free(new_str);
				cout << "Memory was not allocated fot tmp" << endl;
				exit(1);
			}
		}
		
		new_str[length++] = new_sym;
	}


	inputFile.close();
	string result = convert(new_str, length);
	free(new_str);

	ofstream outputFinal("fin.txt");
	outputFinal << result;
	outputFinal.close();
}