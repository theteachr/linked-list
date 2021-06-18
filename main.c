#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node *head;
};

struct Node* get_node(int val) {
    struct Node* new_node = malloc(sizeof(struct Node));

    new_node->data = val;
    new_node->next = NULL;

    return new_node;
}

void insert_at_head(struct LinkedList* list, struct Node* node) {
	// 1 -> 2 -> 3 : 4 ==== 4 -> 1 -> 2 -> 3
	node->next = list->head;
	list->head = node;
}

void insert_at_tail(struct LinkedList* list, struct Node* node) {
	struct Node* tmp;

	if (list->head == NULL) {
		list->head = node;
		return;
	}

	for (tmp = list->head; tmp->next != NULL; tmp = tmp->next);

	tmp->next = node;
}

void remove_at_head(struct LinkedList* list) {
	if (list->head == NULL)
		return;

	list->head = list->head->next;
}

void remove_at_tail(struct LinkedList* list) {
	struct Node* prev = NULL;
	struct Node* curr = list->head;

	if (curr == NULL)
		return;

	if (curr->next == NULL) {
		list->head = NULL;
		free(curr);
		return;
	}

	for (; curr->next != NULL; curr = curr->next)
		prev = curr;

	prev->next = NULL;
	free(curr);
}

void print_linked_list(struct LinkedList* list) {
	struct Node* tmp;

    for (tmp = list->head; tmp->next != NULL; tmp = tmp->next) {
        printf("%d -> ", tmp->data);
    }

	printf("%d\n", tmp->data);
}

void init_linked_list(struct LinkedList* list) {
	list->head = NULL;
}

int main(void) {
    struct Node* one = get_node(1);
    struct Node* two = get_node(2);
    struct Node* thr = get_node(3);

    struct LinkedList nums; // nums.head

	init_linked_list(&nums); // nums.head === NULL

	insert_at_head(&nums, get_node(78));
	print_linked_list(&nums);
	remove_at_tail(&nums);

	insert_at_tail(&nums, get_node(87));
	print_linked_list(&nums);
	remove_at_head(&nums);

	for (int i = 1; i <= 5; i++)
		insert_at_tail(&nums, get_node(i));

	for (int i = 6; i <= 10; i++)
		insert_at_head(&nums, get_node(i));

	remove_at_head(&nums);
	remove_at_tail(&nums);

	print_linked_list(&nums);

    return 0;
}
