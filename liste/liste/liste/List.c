#include "List.h"

void append(List* list, void* data) {
	Node* tmp = malloc(sizeof(Node));
	
	if (list->length == 0) {
		list->head = list->tail = tmp;
	}
	else {
		tmp->prev = list->tail;
		list->tail->next = tmp;
		tmp->next = NULL;
		list->tail = tmp;
	}
	tmp->data = malloc(list->data_size);
	tmp->data = memcpy(tmp->data ,data, list->data_size);

	list->length++;
}

List* get_list(free_function free_data, int data_size) {
	List* list = malloc(sizeof(List));
	list->data_size = data_size;
	list->free_data = free_data;
	list->length = 0;

	return list;
}

Node* get_node_at(List* list, unsigned int index) {
	if (list->length == 0 || index >= list->length)
		return NULL;
	Node* n;
	if ((int)list->length / 2 > index) {
		n = list->head;
		for (int i = 0; i < index; i++)
			n = n->next;
	}
	else {
		n = list->tail;
		for (int i = 0; i < list->length - 1 - index; i++)
			n = n->prev;
	}
	
	return n;
}

void* get_at(List* list, unsigned int index) {
	Node* n = get_node_at(list, index);
	return (n == NULL) ? NULL : n->data;
}

void free_node(List* list, Node* node) {
	list->free_data(node);
	free(node);

	list->length--;
}

void free_char_node(Node* node) {
	free((char*)node->data);
}

void free_list(List* list) {
	Node* n = list->head;
	int liste_size = list->length;
	for (int i = 0; i < liste_size - 1; i++) {
		n = n->next;
		free_node(list, n->prev);
	}
	free_node(list, list->tail);
	free(list);
}