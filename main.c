#include <stdio.h>
#include "linked_list.h"

int main(void) {
	struct LinkedList nums;

	init_linked_list(&nums);

	insert_at_head(&nums, get_node(3));
	print_linked_list(&nums);
	remove_at_tail(&nums);

	print_linked_list(&nums);

	insert_at_tail(&nums, get_node(87));
	print_linked_list(&nums);
	remove_at_head(&nums);

	for (int i = 1; i <= 5; i++)
		insert_at_tail(&nums, get_node(i));
	print_linked_list(&nums);

	for (int i = 6; i <= 10; i++)
		insert_at_head(&nums, get_node(i));
	print_linked_list(&nums);

	remove_at_head(&nums);
	remove_at_tail(&nums);

	print_linked_list(&nums);

	return 0;
}
