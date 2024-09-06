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
    head -> next = NULL; 
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
    toAdd -> data = data;
    toAdd -> next = NULL;
    temp -> next = toAdd;
}
void printLL(struct Node * head)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void solve(struct Node * head)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next != NULL)
    {
        if((temp->data) == (temp->next)->data)
        {
            temp->next = (temp->next)->next;
        }
        else 
        {
            temp = temp->next;
        }
    }
    printLL(head);
}

int main()
{
    int n;
    scanf("%d",&n);

    int temp;
    scanf("%d", &temp);
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    makeNode(head, temp);

    for(int i = 0; i<n-1 ;i++)
    {
        scanf("%d",&temp);
        insertAtTail(head, temp);
    }

    solve(head);

    return 0;
}


