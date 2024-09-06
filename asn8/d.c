#include <stdio.h>
#define SIZE 100000

int top = -1;
int arr[SIZE];

void push(int x);
void pop();
int empty();
int peek();


void nextSmaller(int n, int next[], int arr1[])
{
    push(-1);
    for(int i = n-1; i>=0 ;i--)
    {
        int curr = arr1[i];
        while((peek() != -1) && (arr1[peek()] > curr))
        {
            pop();
        }
        next[i] = peek();
        push(i);
    }
    top = -1;
}
void prevSmaller(int n, int prev[], int arr1[])
{
    push(-1);
    for(int i = 0; i<=n-1 ;i++)
    {
        int curr = arr1[i];
        while((peek() != -1) && (arr1[peek()] > curr))
        {
            pop();
        }
        prev[i] = peek();
        push(i);
    }
    top = -1;
}



int main()
{   
    int n;
    scanf("%d",&n);
    int arr1[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr1[i]);
    }

    int next[n];
    nextSmaller(n, next, arr1);
    int prev[n];
    prevSmaller(n, prev, arr1);

    int area = 0;

    for(int i = 0; i<n ;i++)
    {
        int length = arr1[i];
        int nx = next[i];
        int px = prev[i];
        if(nx == -1)
        {
            nx = n;
        }
        int breadth = nx-px-1;
        int temp_area  = length*breadth;
        if(temp_area > area)
        {
            area = temp_area;
        }
    }   

    printf("%d\n", area);



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