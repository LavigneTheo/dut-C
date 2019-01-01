#include <stdint.h>
#include <stdio.h>

#include "List.h"
#include "Exercice.h"

void process(List* list) {
	char c = 't';
	append(list, &c);
}

void main() {
	
	List* list = get_string_input();

	char c;
	pop(list, 2, &c);
	printf("%c\n", c);

	printf("%s\n", list_to_str(list));

	free_list(list);
}