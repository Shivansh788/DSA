//Q4

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int num;
    struct node *preptr;
    struct node *nextptr;
} *stnode, *ennode;

// Function prototypes
void DlListcreation(int n);
int getMaxNode(struct node *stnode);
void displayDlList();

int main() {
    int n;
    stnode = NULL;
    ennode = NULL;

    // User input for the number of nodes
    printf("\n\n Doubly Linked List : Find maximum value from a doubly linked list :\n");
    printf("--------------------------------------------------------------------------\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    // Creating the doubly linked list
    DlListcreation(n);
    displayDlList();

    // Finding and displaying the maximum value in the linked list
    printf("\n The Maximum Value in the Linked List : %d\n\n", getMaxNode(stnode));
    return 0;
}

// Function to create a doubly linked list
void DlListcreation(int n) {
    int i, num;
    struct node *fnNode;

    if (n >= 1) {
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
                    fnNode->nextptr = NULL;

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

// Function to find the maximum value in the linked list
int getMaxNode(struct node *stnode) {
    if (stnode == NULL) {
        printf(" User message : Invalid Input !!!!\n");
        return INT_MIN; // Returning the minimum integer value when list is empty
    }

    int max = stnode->num;
    while (stnode != NULL) {
        if (stnode->num > max) {
            max = stnode->num;
        }
        stnode = stnode->nextptr;
    }
    return max;
}

// Function to display the doubly linked list
void displayDlList() {
    struct node *tmp;
    int n = 1;
    if (stnode == NULL) {
        printf(" No data found in the List yet.");
    } else {
        tmp = stnode;
        printf("\n\n Data entered in the list are :\n");

        // Loop to display nodes and their data
        while (tmp != NULL) {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; // Moving the current pointer to the next node
        }
    }
}
