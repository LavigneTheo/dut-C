#pragma once
#include <stdio.h>
#include <stdint.h>

typedef void(*free_function)(void*);

typedef struct List {
	int length;
	int data_size;

	free_function free_data;

	struct Node* head;
	struct Node* tail;
}List;

typedef struct Node
{
	void* data;

	struct Node* next;
	struct Node* prev;
}Node;

List* get_list(free_function free_data, int data_size);
void free_node(List* list, Node* node);

void append(List* list, void* data);
void* get_at(List* list, unsigned int index);
void pop(List* list, int index, void* data);

Node* get_node_at(List* list, unsigned int index);

void free_list(List* list);