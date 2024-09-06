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
        temp = temp->next;
    }
    struct Node * toAdd = (struct Node *)malloc(sizeof(struct Node));
    toAdd -> data = data;
    toAdd -> next = head;
    temp -> next = toAdd;
}

void solve(struct Node * head, int n, int a, int b)
{
    if(a == b)
    {
        printf("%d\n", a);
        return;
    }
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node * temp1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    int flag1 = 0;
    int flag2 = 0;
    while (temp->next != head)
    {
        if(temp->data == a)
        {
            temp1 = temp;
            flag1 = 1;
        }
        if(temp->data == b)
        {
            temp2 = temp;
            flag2 = 1;
        }
        if(flag1 && flag2){break;}
        temp = temp->next;
    }

    while(temp1->data != temp2->data)
    {
        temp1 = (temp1->next)->next;
        temp2 = temp2->next;
    }
    printf("%d\n",temp1->data);
   
}

void printLL(struct Node * head)
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);
    printf("\n");
}


int main()
{
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);

    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    int val = 1;
    makeNode(head, val);
    val++;
    for(; val<=n ;val++)
    {
        insertAtTail(head, val);
    }

    // printLL(head);
    solve(head, n, a, b);



    return 0;
}
