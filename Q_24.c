//Q24 Write a C program to delete alternate nodes of a doubly linked list

#include <stdio.h>
#include <stdlib.h>

// using a structure
typedef struct mynode {
    int data;
    struct mynode *prev;    // to point to previous node
    struct mynode *link;    // to point to next node
} node;
node *head = NULL;

// creating the list
void create() {
    node *p, *q;
    int ch;
    do {
        p = (node *)malloc(sizeof(node));
        printf("enter data\n"); 
        scanf("%d", &p->data);
        if (head == NULL) 
        {
            p->prev = head;
            q = p;
        }
        else
        {
            p->prev = q;
            p->link = NULL;
            q->link = p;
            q = p;
        }
        printf("create another node?, press 1   ");
        scanf ("%d",&ch);
    } while(ch==1);
}

//to delete alternate elements
void delete_Alt() {
    if (head == NULL)
        printf("Empty list...ERROR");

    node *previous, *current, *next;    
    previous = head;
    current = head->link;
    while (previous !=NULL && current != NULL) {
        previous->prev = current->prev;
        previous->link = current->link; 

        next = current->link;
        previous->link = next;
        next->prev = previous;

        free(current);
    }
}

// print the list
void display() {
    node *temp;
    temp = head;
    while (temp != NULL) {
        printf("%d  ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    create();
    printf("List before deleting is:    ");
    display();
    delete_Alt();
    printf("List after deleting is:     ");
    display();
return 0;
}

