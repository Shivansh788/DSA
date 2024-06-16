//Q14  Write a C program to move the first element of a doubly linked list to the end.

/* C++ Program to move first element to end 
in a given linked list */
#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct Node {
	int data;
	struct Node* next;
};

/* We are using a double pointer head_ref 
here because we change head of the linked 
list inside this function.*/
void moveToEnd(struct Node** head_ref)
{
	/* If linked list is empty, or it contains 
	only one node, then nothing needs to be 
	done, simply return */
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return;

	/* Initialize first and last pointers */
	struct Node* first = *head_ref;
	struct Node* last = *head_ref;

	/*After this loop last contains address 
	of last node in Linked List */
	while (last->next != NULL) {
		last = last->next;
	}

	/* Change the head pointer to point 
	to second node now */
	*head_ref = first->next;

	/* Set the next of first as NULL */
	first->next = NULL;

	/* Set the next of last as first */
	last->next = first;
}

/* UTILITY FUNCTIONS */
/* Function to add a node at the beginning 
of Linked List */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new_node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Driver program to test above function */
int main()
{
	struct Node* start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printf("\n Linked list before moving first to end\n");
	printList(start);

	moveToEnd(&start);

	printf("\n Linked list after moving first to end\n");
	printList(start);

	return 0;
}
