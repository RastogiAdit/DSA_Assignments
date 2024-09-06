#include <stdio.h>
#define SIZE 1000000

int top = -1;
int arr[SIZE];

void push(int x);
void pop();
int empty();
int peek();

void nextLargest(int n, int arr[], int res[]);
void nextSmallest(int n, int arr[], int res[]);

int main()
{
    int n;
    scanf("%d",&n);
    int peanut[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&peanut[i]);
    }
    
    int arrL[n];
    int arrS[n];
    nextLargest(n, peanut, arrL);
    nextSmallest(n, peanut, arrS);

    for(int i = 0; i<n ;i++)
    {
        printf("%d ",arrL[i]);
    }
    printf("\n");

    for(int i = 0; i<n ;i++)
    {
        printf("%d ",arrS[i]);
    }
    printf("\n");


    return 0;
}

void nextLargest(int n, int arr[], int res[])
{
    push(-1);
    for(int i = n-1; i>=0 ;i--)
    {
        int curr = arr[i];
        while(arr[peek()] < curr && peek() != -1)
        {
            pop();
        }
        if(peek() == -1)
        {
            res[i] = 0;
            push(i);
        }
        else
        {
            res[i] = peek() - i;
            push(i);
        }
    }
    top = -1;
}
void nextSmallest(int n, int arr[], int res[])
{
    push(-1);
    for(int i = n-1; i>=0 ;i--)
    {
        int curr = arr[i];
        while(arr[peek()] > curr && peek() != -1)
        {
            pop();
        }
        if(peek() == -1)
        {
            res[i] = 0;
            push(i);
        }
        else
        {
            res[i] = peek() - i;
            push(i);
        }
    }
    top = -1;
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


int peek()
{
    if(top != -1)
    {
        return arr[top];
    }
    else
    {
        return -1;
    }
}