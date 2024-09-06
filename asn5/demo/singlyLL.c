#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

void makeNode(struct Node * head, int data)
{
    head->data = data;
    head->next = NULL;
}


void printLL(struct Node * head)
{
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtTail(struct Node * head, int data)
{
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    temp->next = newNode;
    
}


int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    makeNode(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    printLL(head);

    return 0;
}