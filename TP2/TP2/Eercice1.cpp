#include "Exercice1.h"

/*
 * MEt une chaine de caract�re dans un tableau et renvoie la taille de chaine sans
 * sans compte rle caract�re d'escape

*/
int get_string_v1(char* str) {
	int i = 0;
	while ((*(str + i++) = getchar()) != '\n');
	str[i - 1] = '\0';
	return i - 1;
}

char* get_string_v2() {
	char tmp[100];

	int i = get_string_v1(tmp);

	char* res = malloc(sizeof(char) * i);
	
	for (int it = 0; it <= i; it++) {
		*(res + it) = *(tmp + it);
	}
	return res;
}

char* get_string_v3() {
	
	char* str = NULL;
	int i = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		char* tmp = malloc(sizeof(char) * i);
		for (int it = 0; it < i; it++)
			*(tmp + it) = *(str + it);
		free(str);
		str = malloc(sizeof(char) * i + 2);
		for (int it = 0; it < i; it++)
			*(str + it) = *(tmp + it);
		*(str + i) = (char)c;
		*(str + ++i) = '\0';
		free(tmp);
	}

	return str;
}

void print_str(char* str) {
	int i = 0;
	while (*(str + i) != '\0')
		printf("%c", *(str + i++));
}