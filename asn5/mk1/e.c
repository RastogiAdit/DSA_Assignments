#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void makeNode(struct Node * head, int data)
{
    head -> data = data;
    head -> next = head;
}

void insertAtTail(struct Node * head, int data)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = head;
    temp -> next = toAdd;
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


void solve(struct Node * head, int n, int k)
{   
    if(n == 1)
    {
        printf("1\n");
        return;
    }
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    if(k == 1)
    {
        while(temp->next != head)
        {
            temp = temp->next;
        }
        printf("%d\n", temp->data);
        return;
    }
    for(int i = 0; i<n-1 ;i++)
    {
        for(int j = 0; j<k-2 ;j++)
        {
            temp = temp->next;
        }
        temp->next = (temp->next)->next;
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}


int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int val = 1;
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    makeNode(head, val);
    for(int i = val+1; i<=n ;i++)
    {
        insertAtTail(head, i);
    }

    solve(head, n, k);


    return 0;
}