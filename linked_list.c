// single linked list
/*#include<stdio.h>
struct node
{
    int data;
    struct node *next;//for storing pointer variable for next address
}

//DOUBLE LINK LIST
#include<stdio.h>
struct node
{
    int data;
    struct node *prev;//for storing pointer variable for next address
    struct node *next;//stores address of next
}*/

//
/*#include<stdio.h>
struct student
{
    int roll;
    char name[50];
    int age;
    struct student *next;
};
int main()
{
    struct student n1,n2,n3;
    struct student *head;
    scanf("%d %s %d",&n1.roll,n1.name,&n1.age);
    scanf("%d %s %d",&n2.roll,n2.name,&n2.age);
    scanf("%d %s %d",&n3.roll,n3.name,&n3.age);
    head=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=NULL;//for circular linked list => n3.next=&n1
    while(head!=NULL)
    {
        printf("%d %s %d",head->roll,head->name,head->age);
        head=head->next;
    }

}*/
/*#include<stdio.h>
struct student
{
    int roll;
    char name[20];
    int age;
    struct student *next;
};
int main()
{
    struct student n1,n2,n3;
    struct student *head;
    scanf("%d %s %d",&n1.roll,n1.name,&n1.age);
       scanf("%d %s %d",&n2.roll,n2.name,&n2.age);
          scanf("%d %s %d",&n3.roll,n3.name,&n3.age);
          head=&n1;
          n1.next=&n2;
          n2.next=&n3;
          n3.next=NULL;
          while(head!=NULL)
          {
            printf("%d %s %d",head->roll,head->name,head->age);
            head=head->next;
          }
}*/

/*#include<stdio.h>
struct bollywood
{
    char movie_name[20];
    int date;
    char director[20];
    struct bollywood *next;
};
int main()
{
    struct bollywood n1,n2;
    struct bollywood *head;
    scanf("%d %s %d",n1.movie_name,&n1.date,n1.director);
        scanf("%d %s %d",n2.movie_name,&n2.date,n2.director);
        head=&n1;
        n1.next=&n2;
        n2.next=NULL;
        while(head!=NULL)
        {
            printf("%d %s %d",head->movie_name,head->date,head->director);
            head=head->next;
        }
}*/
/*#include<stdio.h>
struct employee
{
    int employee_name[20];

}*/

// ON FILE
/*#include<stdio.h>
int main()
{
    FILE *fp;
    char *c;
    fp=fopen("D:/Test/input.txt","w");
    while((c=getchar)!=EOF)
    {
        put(c,fp);
    }
    fclose(fp);
    fp=fopen("D:/Test/input.txt","r");
    while(c=getc(fp)!=EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
}*/

// INSERTION AND DELETION AT THE BEGINING
/*#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
void insert_begin(struct Node **head,int value)//head ka address nikalne ke liye **
{
    struct Node newnode=(struct Node)malloc(sizeof(struct Node));// allocate memory for new node
    newnode->data=value;//assigning value to new node
    newnode->next= *head;
    *head = newnode;
}
void delete_begin(struct Node **head)
{
    if(*head==NULL)
    {
        printf("The linked list is already empty.");//no node in linked list
        return;
    }
    else
    {
        struct Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void insert_end(struct Node **head,int value)
{
    struct Node newnode=(struct Node)malloc(sizeof(struct Node));
    struct Node *temp=*head;
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;//incrementing the next node
    }
    temp->next=newnode;
}
int main()
{
    struct node *head=NULL;
    insert_begin(&head,10);
    insert_begin(&head,20);
    insert_end(&head,30);
    delete_begin(&head);
    while(head!=NULL)
    {
         printf("%d ",head->data);
        head=head->next;
    }
}*/

// INSERT AT ANY POSITION
/*#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
void insertanyposition(struct Node **head, int value, int position)
{
    if (position == 0)
    {
        printf("invalid position");
        return;
    }
    if (position == 1)
    {
        insertatbegin(head, value);
        return;
    }
    int loc++;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // allocating memory for new node
    newNode->data = value;
    struct Node *temp = *head;
    for (int count = 1; count < position; count++)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
            loc++;
        }
    }
    if (loc < position)
    {
        printf("Invalid position");
        return;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
int main()
{
    struct Node *head = NULL;
    insertanyposition(&head, 10, 2);
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}*/

#include<stdio.h>
struct Node
{
    int data;int temp;
    struct Node *next;
};
void Deleteatend(struct Node **head)
{
    if(*head==NULL)
    {
        printf("The list is already empty");
        return;
    }
    struct Node *temp=*head;
    struct Node *prev=NULL;//DECLARED as null
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if (prev==NULL)
    {
        *head=NULL;
    }
    else
    {
        prev->next=NULL;
    }
    free(temp);
}
void deleteanyposition(struct Node **head,int position)
{
    struct Node *temp=*head;
    struct Node *prev=NULL;
    if(position==1)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    for(int i=1;temp!=NULL && i<position;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invalid position");
        return;
    }
    prev->next=temp->next;
    free(temp); 
}
void display(struct Node **head)
{
    struct Node *temp=*head;
    while(temp->next!=NULL)
    {
        printf("%d",temp->data);
        printf("\n");
    }
}
int main()
{
    struct Node *head=NULL;
    insertatbegining(&head,10);
    insertatbegining(&head,5);
    display(&head);
    insertatend(&head,7);
    insertatanyposition(&head,15,2);
    deleteatbegining(&head);
    deleteatend(&head);
    deleteanyposition(&head,3);
    display(&head);
    return 0;
}



// take a list as input then searching element via linkedlist

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;           // Data
    struct node* next;  // Address
} *head;

// Function to create a list of n nodes
void createList(int n) {
    struct node* newNode, *temp;
    int data, i;

    head = malloc(sizeof(struct node));

    // Unable to allocate memory, exit from app
    if (head == NULL) {
        printf("Unable to allocate memory. Exiting from app.");
        exit(0);
    }

    // Input data for the head node
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    head->data = data;  // Link data field with data
    head->next = NULL;  // Link address field to NULL

    temp = head;

    // Create n nodes and add them to the list
    for (i = 2; i <= n; i++) {
        newNode = malloc(sizeof(struct node));

        // If memory allocation fails
        if (newNode == NULL) {
            printf("Unable to allocate memory. Exiting from app.");
            exit(0);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;  // Link previous node to the new node
        temp = newNode;        // Move temp to the new node
    }
}

// Function to search for an element by key
int search(int key) {
    int index = 0;
    struct node* curNode = head;

    while (curNode != NULL) {
        if (curNode->data == key) {
            return index;  // Element found
        }
        curNode = curNode->next;
        index++;
    }

    return -1;  // Element not found
}

int main() {
    int n, keyToSearch, index;

    // Input the number of nodes to create
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    createList(n);

    // Display the list
    printf("\nData in the list:\n");
    // Display the linked list (not shown here)

    // Input the element to search
    printf("\nEnter the element to search: ");
    scanf("%d", &keyToSearch);

    // Call the search function
    index = search(keyToSearch);

    if (index >= 0) {
        printf("%d found in the list at position %d\n", keyToSearch, index + 1);
    } else {
        printf("%d not found in the list.\n", keyToSearch);
    }

    return 0;
}


// define the largest integer in list 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MIN

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to find the largest element

int findLargest(struct Node* head) {
    int max = INT_MIN;  // Initialize max to smallest possible value
    struct Node* current = head;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;  // Update max if current data is larger
        }
        current = current->next;
    }

    return max;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example: Create a linked list with some data
    struct Node* head = createNode(15);
    head->next = createNode(14);
    head->next->next = createNode(13);
    head->next->next->next = createNode(22);
    head->next->next->next->next = createNode(17);

    // Find the largest element
    int largest = findLargest(head);

    printf("Largest element in the linked list: %d\n", largest);

    // Clean up memory (free nodes)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


// student data using linked list and switch



