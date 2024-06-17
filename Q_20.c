//Q20 Write a C program that removes elements with even indices from a circular linked list.

#include<stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to remove elements with even indices from a linked list
void remove_Even_indices(struct Node** head) {
    struct Node* current = *head; // Pointer to traverse the list
    struct Node* prev = NULL; // Pointer to track the previous node
    int count = 0; // Variable to track the index of nodes, starting from 0

    // Traverse the linked list
    while (current != NULL) {
        if (count % 2 == 0) { // Check if the index is even
            if (prev == NULL) {
                *head = current->next; // Update head if the even index is the head node
            } else {
                prev->next = current->next; // Skip the node at even index
            }
            struct Node* temp = current; // Store the current node to free it later
            current = current->next; // Move to the next node
            free(temp); // Free the memory of the removed node
        } else {
            prev = current; // Move the 'prev' pointer to the current node
            current = current->next; // Move to the next node
        }
        count++; // Increment the index count
    }
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); // Allocate memory for a new node
    new_node->data = data; // Assign data to the new node
    new_node->next = *head; // Set the next of the new node to the current head
    *head = new_node; // Update the head to point to the new node
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) { // Iterate through the linked list
        printf("%d ", head->data); // Print the data of the current node
        head = head->next; // Move to the next node
    }
    printf("\n"); // Print a new line after printing all nodes
}

// Test function to demonstrate the removal of even-indexed elements
int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Create a linked list with some initial values
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);

    printf("Original linked list:\n");
    printList(head); // Display the original linked list

    remove_Even_indices(&head); // Call function to remove even-indexed elements

    printf("\nLinked list after removing even indices:\n");
    printList(head); // Display the modified linked list after removal

    return 0; // Indicate successful completion of the program
}



