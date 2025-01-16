//Q23 Write a C program to reverse a singly linked list in pairs.

#include<stdio.h>
#include <stdlib.h>

// Structure defining a node in a singly linked list
struct Node {
    int data; // Data stored in the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node in the singly linked list
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); // Allocate memory for a new node
    temp->data = data; // Assign data to the new node
    temp->next = NULL; // Initialize the next pointer as NULL
    return temp; // Return the new node
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data); // Print the data of the current node
        head = head->next; // Move to the next node
    }
    printf("\n");
}

// Function to reverse the singly linked list in pairs
void reverse_Pairs(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return; // If the list is empty or has only one element, return

    struct Node* temp = *head;
    *head = (*head)->next; // Update the head to point to the second node
    temp->next = (*head)->next; // Adjust the first node's next pointer to point to the third node
    (*head)->next = temp; // Adjust the second node's next pointer to point to the first node

    struct Node* prev = temp; // Set the previous node as the first node
    temp = temp->next; // Move to the third node

    // Reverse pairs of nodes until the end of the list or a single node is left
    while (temp != NULL && temp->next != NULL) {
        prev->next = temp->next; // Point the previous node to the next pair's starting node
        temp->next = temp->next->next; // Skip the next pair's starting node
        prev->next->next = temp; // Reverse the next pair and connect it to the previous pair
        prev = temp; // Move to the next pair's starting node
        temp = temp->next; // Move to the next pair
    }
}

// Main function
int main() {
    // Creating and populating the first linked list
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    printf("Original List: ");
    printList(head); // Displaying the original list

    reverse_Pairs(&head); // Reverse the linked list in pairs
    printf("Reverse a singly linked list in pairs:\n");
    printList(head); // Display the list after reversing pairs

    // Creating and populating the second linked list
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    printf("\nOriginal List: ");
    printList(head1); // Displaying the original list

    reverse_Pairs(&head1); // Reverse the linked list in pairs
    printf("Reverse a singly linked list in pairs:\n");
    printList(head1); // Display the list after reversing pairs

    return 0;
}


