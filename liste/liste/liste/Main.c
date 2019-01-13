#include <stdint.h>
#include <stdio.h>

#include "List.h"
#include "Exercice.h"

void process(List* list) {
	char c = 't';
	append(list, &c);
}

void main() {
	
	List* list = get_list(NULL, sizeof(char));

	char c = 't';
	insert(list, &c, 0);
	c = 'h';
	insert(list, &c, 1);
	c = 'e';
	insert(list, &c, 2);
	c = 'o';
	insert(list, &c, 3);
	c = 'a';
	insert(list, &c, 2);

	printf("%s\n", list_to_str(list));

	free_list(list);
}