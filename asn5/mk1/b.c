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

void solve(struct Node * head1, struct Node * head2, int a, int b)
{
    int carry = 0;
    struct Node * temp1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp1 = head1;
    temp2 = head2;
    
    while(temp1 != NULL && temp2!= NULL)
    {
        if(temp1->data >= temp2->data)
        {
            printf("%d ",temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            printf("%d ",temp1->data);
            temp1 = temp1->next;
        }
    }
    if(temp1 == NULL)
    {
        while(temp2 != NULL)
        {
            printf("%d ",temp2->data);
            temp2 = temp2->next;
        }
    }
    if(temp2 == NULL)
    {
        while(temp1 != NULL)
        {
            printf("%d ",temp1->data);
            temp1 = temp1->next;
        }
    }
}


int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    struct Node * head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node * head2 = (struct Node*)malloc(sizeof(struct Node));

    int temp;
    scanf("%d", &temp);
    makeNode(head1, temp);
    for(int i = 0; i<a-1 ;i++)
    {
        scanf("%d", &temp);
        insertAtTail(head1, temp);
    }
    scanf("%d", &temp);
    makeNode(head2, temp);
    for(int i = 0; i<b-1 ;i++)
    {
        scanf("%d", &temp);
        insertAtTail(head2, temp);
    }

    solve(head1, head2, a, b);

    return 0;
}