#include <stdint.h>
#include <stdio.h>

#include "Liste.h"
#include "Exercice.h"

void main() {
	
	List* list = get_list(&free_char_node, sizeof(char));
	
	char a = 'a';
	append(list, &a);

	a = 'b';
	append(list, &a);

	a = 'c';
	append(list, &a);

	a = 'd';
	append(list, &a);

	a = 'e';
	append(list, &a);

	
	list_to_str(list);

	free_list(list);
}