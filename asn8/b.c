#include <stdio.h>
#define SIZE 100000

int front = -1;
int rear = -1;
int arr[SIZE];
void enqueue(int x); //push
void pop(); //removes one element
int dequeue();  //returns element
int isEmpty();

int max()
{
    int max = arr[front];
    for(int i = front+1; i<=rear ;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n;
    scanf("%d",&n);
    int w;
    scanf("%d",&w);
    
    for(int i = 0; i<w ;i++)
    {
        int temp;
        scanf("%d",&temp);
        enqueue(temp);
    }
    printf("%d ",max());
    for(int i = 0; i<n-w ;i++)
    {
        int temp;
        scanf("%d",&temp);
        enqueue(temp);
        pop();
        printf("%d ",max());
    }


    return 0;
}

void enqueue(int x)
{
    if(front < SIZE - 1)
    {
        if(front == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = x; 
    }
}
void pop()
{
    if((front <= rear) && (front != -1))
    {
        front++;
    }
}
int dequeue()
{
    if(front != -1)
    {
        return arr[front];
    }
    else
    {
        return -1;
    }
}
int isEmpty()
{
    if((front > rear) || (front == -1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}