//Q9 Write a program in C to delete a node from the last node of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *preptr;
    struct node *nextptr;
} *stnode, *ennode;

// Function prototypes
void DlListcreation(int n);
void DlListDeleteLastNode();
void displayDlList(int a);

int main() {
    int n, a;
    stnode = NULL;
    ennode = NULL;

    // User input for the number of nodes
    printf("\n\n Doubly Linked List : Delete node from the last of a doubly linked list :\n");
    printf("-----------------------------------------------------------------------------\n");
    printf(" Input the number of nodes (3 or more ): ");
    scanf("%d", &n);

    // Creating the doubly linked list
    DlListcreation(n);
    a = 1;
    displayDlList(a);

    // Deleting the last node from the doubly linked list
    DlListDeleteLastNode();
    a = 2;
    displayDlList(a);

    return 0;
}

// Function to create a doubly linked list
void DlListcreation(int n) {
    int i, num;
    struct node *fnNode;

    if (n >= 1) {
        // Allocating memory for the first node
        stnode = (struct node *)malloc(sizeof(struct node));
        if (stnode != NULL) {
            // Input data for the first node
            printf(" Input data for node 1 : ");
            scanf("%d", &num);
            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;

            // Loop to create subsequent nodes and link them
            for (i = 2; i <= n; i++) {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if (fnNode != NULL) {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;    // Linking new node with the previous node
                    fnNode->nextptr = NULL;     // Setting next address of fnNode as NULL
                    ennode->nextptr = fnNode;   // Linking previous node with the new node
                    ennode = fnNode;            // Assigning new node as last node
                } else {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        } else {
            printf(" Memory can not be allocated.");
        }
    }
}

// Function to delete the last node from the doubly linked list
void DlListDeleteLastNode() {
    struct node *NodeToDel;

    if (ennode == NULL) {
        printf(" Delete is not possible. No data in the list.\n");
    } else {
        NodeToDel = ennode;
        ennode = ennode->preptr;    // Move the previous address of the last node to the 2nd last node
        ennode->nextptr = NULL;     // Set the next address of last node to NULL
        free(NodeToDel);            // Delete the last node
    }
}

// Function to display the doubly linked list
void displayDlList(int m) {
    struct node *tmp;
    int n = 1;
    if (stnode == NULL) {
        printf(" No data found in the List yet.");
    } else {
        tmp = stnode;
        if (m == 1) {
            printf("\n Data entered in the list are :\n");
        } else {
            printf("\n After deletion the new list are :\n");
        }
        // Loop to display nodes and their data
        while (tmp != NULL) {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // Moving the current pointer to the next node
        }
    }
}
