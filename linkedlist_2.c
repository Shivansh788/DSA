// 14/02/2024

#include<stdio.h>
#include<stdlib.h>

// In your header file (list.h):
#ifndef LIST_H
#define LIST_H

// Declare the struct node without defining it completely
struct Node;

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} NODE;

typedef struct list {
    NODE node;
    int count;
} LIST;

extern void listDelete(LIST *pList, NODE *pNode);
extern void listFree(LIST *pList);

#endif


void insert_at_begining(struct Node **head, int value){
    struct Node * newNode= (struct Node*)malloc(sizeof(struct Node));
        newNode -> data = 7;
        newNode -> previous;
        newNode -> next;
}
