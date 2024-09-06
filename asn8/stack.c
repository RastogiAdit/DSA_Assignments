#include <stdio.h>
#define SIZE 100000

int top = -1;
int arr[SIZE];

void push(int x);
void pop();
int empty();
void peek();


int main()
{
    return 0;
}


void push(int x)
{
    if(top != SIZE -1)
    {
        top++;
        arr[top] = x;
    }
    else
    {
        printf("Stack Full\n");
    }
}

void pop()
{
    if(top != -1)
    {
        top--;
    }
    else
    {
        printf("Stack Empty\n");
    }
}


int empty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void peek()
{
    if(top != -1)
    {
        printf("%d\n",arr[top]);
    }
    else
    {
        printf("Stack Empty\n");
    }
}