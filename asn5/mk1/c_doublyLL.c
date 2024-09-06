#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * pre;
    struct Node * next;
};

void makeNode(struct Node * head, int data)
{
    head->data = data;
    head->pre = NULL;
    head->next = NULL;
}

void insertAtTail(struct Node * head, int data)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd->data = data;
    toAdd->pre = temp;
    toAdd->next = NULL;
    temp->next = toAdd;
}




void solve(struct Node * head)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->pre;
    }
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

int main()
{
    int n;
    scanf("%d", &n);
    struct Node * head = (struct Node*)malloc(sizeof(struct Node));
    int temp;
    scanf("%d", &temp);
    makeNode(head, temp);
    for(int i = 0; i<n-1 ;i++)
    {
        scanf("%d", &temp);
        insertAtTail(head, temp);
    }

    solve(head);
    

    return 0;
}