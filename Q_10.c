//Q10  Write a program in C to insert a node at any position in a circular linked list.

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in a circular linked list
struct node {
    int num;
    struct node *nextptr;
} *stnode;

// Function prototypes
void ClListcreation(int n);
void ClLinsertNodeAtBeginning(int num);
void ClLinsertNodeAtAny(int num, int pos);
void displayClList(int a);

int main() {
    int n, num1, a, insPlc;
    stnode = NULL;

    // User input for the number of nodes
    printf("\n\n Circular Linked List : Insert a node at any position in a circular linked list :\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    // Creating a circular linked list
    ClListcreation(n);
    a = 1;
    displayClList(a);

    // Input the position and data to insert a new node
    printf(" Input the position to insert a new node : ");
    scanf("%d", &insPlc);
    printf(" Input data for the position %d : ", insPlc);
    scanf("%d", &num1);
    ClLinsertNodeAtAny(num1, insPlc);
    a = 2;
    displayClList(a);

    return 0;
}

// Function to create a circular linked list
void ClListcreation(int n) {
    int i, num;
    struct node *preptr, *newnode;

    if (n >= 1) {
        stnode = (struct node *)malloc(sizeof(struct node));
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        preptr = stnode;

        // Loop to create subsequent nodes and link them to form a circular list
        for (i = 2; i <= n; i++) {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &num);
            newnode->num = num;
            newnode->nextptr = NULL; // Setting the next address of the new node as NULL
            preptr->nextptr = newnode; // Linking the previous node with the new node
            preptr = newnode; // Advancing the previous node to the new node
        }
        preptr->nextptr = stnode; // Linking the last node with the first node to form a circular list
    }
}

// Function to insert a node at the beginning of the circular linked list
void ClLinsertNodeAtBeginning(int num) {
    struct node *newnode, *curNode;

    if (stnode == NULL) {
        printf(" No data found in the List yet.");
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = stnode;
        curNode = stnode;
        while (curNode->nextptr != stnode) {
            curNode = curNode->nextptr;
        }
        curNode->nextptr = newnode;
        stnode = newnode;
    }
}

// Function to insert a node at any given position in the circular linked list
void ClLinsertNodeAtAny(int num, int pos) {
    struct node *newnode, *curNode;
    int i;

    if (stnode == NULL) {
        printf(" No data found in the List yet.");
    } else if (pos == 1) {
        ClLinsertNodeAtBeginning(num);
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        curNode = stnode;

        // Loop to find the position before the desired position to insert the new node
        for (i = 2; i <= pos - 1; i++) {
            curNode = curNode->nextptr;
        }
        newnode->nextptr = curNode->nextptr;
        curNode->nextptr = newnode;
    }
}

// Function to display the circular linked list
void displayClList(int m) {
    struct node *tmp;
    int n = 1;

    if (stnode == NULL) {
        printf(" No data found in the List yet.");
    } else {
        tmp = stnode;
        if (m == 1) {
            printf("\n Data entered in the list are :\n");
        } else {
            printf("\n After insertion the new list are :\n");
        }

        // Loop to display nodes in the circular list
        do {
            printf(" Data %d = %d\n", n, tmp->num);
            tmp = tmp->nextptr;
            n++;
        } while (tmp != stnode);
    }
}
