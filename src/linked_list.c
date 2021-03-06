#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct Node* get_node(int val) {
	struct Node* new_node = malloc(sizeof(struct Node));

	new_node->data = val;
	new_node->next = NULL;

	return new_node;
}

int is_empty(struct LinkedList* list) {
	return list->head->next == NULL;
}

void insert_at_head(struct LinkedList* list, struct Node* node) {
	node->next = list->head->next;
	list->head->next = node;
}

void insert_at_tail(struct LinkedList* list, struct Node* node) {
	struct Node* tmp;

	for (tmp = list->head; tmp->next != NULL; tmp = tmp->next);
	tmp->next = node;
}

void remove_at_head(struct LinkedList* list) {
	struct Node* tmp = list->head->next;

	if (is_empty(list))
		return;

	list->head->next = list->head->next->next;
	free(tmp);
}

void remove_at_tail(struct LinkedList* list) {
	struct Node* prev = list->head;
	struct Node* curr = list->head;

	if (is_empty(list))
		return;

	for (; curr->next != NULL; curr = curr->next)
		prev = curr;

	prev->next = NULL;
	free(curr);
}

void print_linked_list(struct LinkedList* list) {
	struct Node* tmp;

	if (is_empty(list)) {
		printf("List is empty.\n");
		return;
	}

	for (tmp = list->head->next; tmp->next != NULL; tmp = tmp->next) {
		printf("%d -> ", tmp->data);
	}

	printf("%d\n", tmp->data);
}

void init_linked_list(struct LinkedList* list) {
	list->head = get_node(0);
}
