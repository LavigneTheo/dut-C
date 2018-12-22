#include "Exercice.h"

char* list_to_str(List* list) {
	char* str = malloc(sizeof(char) * list->length + 1);
	*(str + list->length) = '\0';
	for (int i = 0; i < list->length; i++)
		*(str + i) = *(char*)get_at(list, i);
	
	return str;
}