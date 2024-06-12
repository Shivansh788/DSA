//Q5   Write a program in C to search for an element in a circular linked list.

/**
 * C program to search an element in a Circular Linked List
 */

#include <stdio.h>
#include <stdlib.h>


/* Basic node structure */
struct node {
    int data;
    struct node * next;
};


/* Function declaration */
void createList(struct node **head, int n);
void displayList(struct node *head);
int  search(struct node *head, int key);


int main()
{
    int n, choice, index;

    struct node *head = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        printf("--------------------------------------------\n");
        printf("        CIRCULAR LINKED LIST PROGRAM        \n");
        printf("--------------------------------------------\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Search element\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter total node to create: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            
            case 2:
                displayList(head);
                getchar(); // Hold screen
                getchar(); // Hold screen
                break;
            
            case 3:
				printf("Enter element to search: ");
				scanf("%d", &n);
				index = search(head, n);

				if (index == -1)
					printf("%d not found in list.\n", n);
				else 
                	printf("%d found at %d position.\n", n, (index + 1));
                
				getchar(); // Hold screen
                getchar(); // Hold screen
                break;

            case 0:
                printf("Exiting from application");
                exit(0);
                break;

            default:
                printf("Error! Invalid choice. Please choose between 0-3");
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}


/**
 * Function to search an element in list. 
 * Returns index of element if exists in list, 
 * otherwise returns -1.
 */
int search(struct node *head, int key)
{
	int index = 0;
    struct node *current = head;

    // Iterate till end of list
    do 
    {
		// Nothing to look into
		if (current == NULL)
			return;
		
		if (current->data == key)
			return index;

        current = current->next;
		index++;
    } while (current != head);

    // Element not found in list
    return -1;
}


/**
 * Creates a circular linked list of n nodes.
 */
void createList(struct node **head, int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    prevNode = NULL;
    newNode  = NULL;


    /* Creates and links rest of the n-1 nodes */
    for(i=1; i<=n; i++)
    {
        // Create a new node
        newNode = (struct node *) malloc(sizeof(struct node));

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        // Link the previous node with newly created node
        if (prevNode != NULL)
            prevNode->next = newNode;

        // Move the previous node ahead
        prevNode = newNode;

        // Link head node if not linked
        if (*head == NULL)
            *head = newNode;
    }

    // Link last node with first node
    prevNode->next = *head;

    printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
}


/**
 * Display node content of circular linked list
 */
void displayList(struct node *head)
{
    struct node *current;
    int n = 1;

    // Nothing to print in list
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }


    current = head;
    printf("DATA IN THE LIST:\n");

    do 
    {
        // Print current node
        printf("Data %d = %d\n", n++, current->data);

        // Move to next node
        current = current->next;
    } while (current != head);
}
