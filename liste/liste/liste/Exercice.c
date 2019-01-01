#include "Exercice.h"

char* list_to_str(List* list) {
	char* str = malloc(sizeof(char) * list->length + 1);
	*(str + list->length) = '\0';
	for (int i = 0; i < list->length; i++)
		*(str + i) = *(char*)get_at(list, i);
	
	return str;
}

List* get_string_input() {
	char c;
	List* list = get_list(NULL, sizeof(char));
	while ((c = getchar()) != '\n') {
		append(list, &c);
	}
	return list;
}