#include "Exercice3.h"

void get_info(char* str, int* letters, int* not_alpha, int* total_char) {
	int i = 0;
	*not_alpha = 0; *total_char = 0;
	while (*(str + i) != '\0') {
		int val = (int)*(str++ + i);
		if (val >= 65 && val <= 90)
			(*(letters + val - 65))++;
		else if (val >= 97 && val <= 122)
			(*(letters + val - 97))++;
		else
			*(not_alpha)++;

		(*total_char)++;
	}
}

int* get_info_2(char* str) {
	int i = 0;
	int* arr = calloc(sizeof(char) * 28);
	while (*(str + i) != '\0') {
		int val = (int)*(str++ + i);
		if (val >= 65 && val <= 90)
			(*(arr + val - 65))++;
		else if (val >= 97 && val <= 122)
			(*(arr + val - 97))++;
		else
			(*(arr + 26))++;

		(*(arr + 27))++;
	}
	return arr;
}