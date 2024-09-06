#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

//circular ll
void makeNode(struct Node * head, int data)
{
    head -> data = data;
    head -> next = head;
}

void insertAtTail(struct Node* head, int data)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = head;
    temp->next = toAdd;
}

void printLL(struct Node* head)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

void solve(struct Node * head, int shift)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    for(int i = 0; i<shift ;i++)
    {
        temp = temp->next;
    }
    printLL(temp);
}

int main()
{
    int n,shift;
    scanf("%d %d",&n,&shift);

    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    int temp;
    scanf("%d",&temp);
    makeNode(head, temp);
    for(int i = 0; i<n-1 ;i++)
    {
        scanf("%d",&temp);
        insertAtTail(head, temp);
    }
    solve(head, shift);


    return 0;
}
