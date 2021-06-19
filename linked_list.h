#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Node {
	int data;
	struct Node* next;
};

struct LinkedList {
	struct Node *head;
};

struct Node* get_node(int);
void init_linked_list(struct LinkedList*);
void insert_at_head(struct LinkedList*, struct Node*);
void insert_at_tail(struct LinkedList*, struct Node*);
void remove_at_head(struct LinkedList*);
void remove_at_tail(struct LinkedList*);
void print_linked_list(struct LinkedList*);
int is_empty(struct LinkedList*);

#endif
