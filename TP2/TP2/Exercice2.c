#include "Exercice2.h"


int count(char* str) {
	int i = 0;
	while (str[++i] != '\0');
	return i;
}

char* suppr(char * str, char c) {
	int suppr_count = 0;
	for (int i = 0; i < count(str); i++) {
		if (*(str + i) == c)
			suppr_count++;
	}
	
	char * res = malloc(sizeof(char) * (count(str) - suppr_count) + 1);
	int it_res = 0;
	*(res + count(str) - suppr_count) = '\0';
	for (int i = 0; i < count(str); i++) {
		if (*(str + i) != c)
			*(res + it_res++) = *(str + i);
	}
	return res;
}

char* doubleChar(char* str, char c) {
	int double_cout = 0;
	for (int i = 0; i < count(str); i++) {
		if (*(str + i) == c)
			double_cout++;
	}

	char * res = malloc(sizeof(char) * (count(str) + double_cout) + 1);
	int it_res = 0;
	*(res + count(str) + double_cout) = '\0';
	for (int i = 0; i < count(str); i++) {
		if (*(str + i) == c)
			*(res + it_res++) = *(str + i);
		*(res + it_res++) = *(str + i);
	}
	return res;
}

