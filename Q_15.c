//Q15 Write a program in C to delete a node from the middle of a circular linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the middle of the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL)
        return;

    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Traverse to find the node to be deleted
    while (curr->data != key) {
        prev = curr;
        curr = curr->next;
        if (curr == *head)
            break; // Node not found
    }

    // If the node is found
    if (curr == *head) {
        // If it's the only node
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
        } else {
            // If it's the first node
            struct Node* temp = *head;
            while (temp->next != *head)
                temp = temp->next;
            temp->next = curr->next;
            *head = curr->next;
            free(curr);
        }
    } else {
        // If it's not the first or last node
        prev->next = curr->next;
        free(curr);
    }
}

// Example usage
int main() {
    struct Node* head = NULL;
    // Create your circular linked list here (push nodes)

    // Delete a node with data = 5 (for example)
    deleteNode(&head, 5);

    // Display the updated list (printList function not shown here)
    // ...

    return 0;
}


