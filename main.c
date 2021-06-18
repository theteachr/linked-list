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

	for (tmp = list->head; tmp->next != NULL; tmp = tmp->next);

	tmp->next = node;
}

void print_linked_list(struct LinkedList* list) {
	struct Node* tmp;

    for (tmp = list->head; tmp->next != NULL; tmp = tmp->next) {
        printf("%d -> ", tmp->data);
    }

	printf("%d\n", tmp->data);
}

int main(void) {
    struct Node* one = get_node(1);
    struct Node* two = get_node(2);
    struct Node* thr = get_node(3);

    struct LinkedList nums;

    nums.head = one;

	insert_at_head(&nums, two);
	insert_at_head(&nums, thr);

	for (int i = 4; i <= 10; i++)
		insert_at_tail(&nums, get_node(i));

	print_linked_list(&nums);

    return 0;
}
