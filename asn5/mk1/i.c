#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node * next;
    struct Node * pre;
};

void makeNode(struct Node * head, char data)
{
    head -> data = data;
    head -> next = NULL;
    head -> pre = NULL;
}

void insertAtTail(struct Node * head, char data)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = NULL;
    toAdd -> pre = temp;
    temp -> next = toAdd;
}

void printLL(struct Node * head)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;

    while(temp != NULL)
    {
        printf("%c ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void solve(struct Node * head, int n)
{
    struct Node * temp1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp1 = head;
    temp2 = head;
    while(temp2 -> next != NULL)
    {
        temp2 = temp2 -> next;
    }

    for(int i = 0; i<n/2 ;i++)
    {
        if((temp1 -> data) != (temp2 -> data))
        {
            printf("NO\n");
            return;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> pre;
    }
    printf("YES\n"); 
}




int main()
{
    int n;
    scanf("%d",&n);
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    char temp;
    scanf(" %c", &temp);
    makeNode(head, temp);
    for(int i = 0; i<n-1 ;i++)
    {
        scanf(" %c", &temp);
        insertAtTail(head, temp);
    }

    solve(head, n);


    
    return 0;
}