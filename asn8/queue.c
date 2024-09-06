#include <stdio.h>
#define SIZE 100000

int front = -1;
int rear = -1;
int arr[SIZE];
void enqueue(int x); //push
void pop();
int dequeue();  
int isEmpty();

int main()
{

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