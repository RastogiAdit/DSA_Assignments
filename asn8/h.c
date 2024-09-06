#include <stdio.h>

void push(int num, int arr_min[], int arr_max[], int size)
{
    arr_max[size] = num;
    arr_min[size] = num;
}

void pop_min(int arr_min[], int size)
{
    for(int i = 0; i<size ;i++)
    {
        arr_min[i] = arr_min[i+1];
    }
}

void print_min_in_maxHeap(int arr_max[], int size)
{
    int min = arr_max[0];
    for(int i = 1; i<size ;i++)
    {
        if(arr_max[i] < min)
        {
            min = arr_max[i];
        }
    }
    printf("%d ",min);
}

void print_avg_in_minHeap(int arr_min[], int size)
{
    int sum = 0;
    for(int i = 0; i<size ;i++)
    {
        sum += arr_min[i];
    }
    printf("%d\n",sum/size);
}

int main()
{
    int t;
    scanf("%d",&t);
    int arr_max[100];
    int arr_min[100];
    int size = 0;

    while(t--)
    {
        int task;
        scanf("%d",&task);
        if(task == 1)
        {
            int num;
            scanf("%d",&num);
            push(num, arr_min, arr_max, size);
            size++;
            continue;
        }
        if(task == 2)
        {
            size--;
            pop_min(arr_min, size);
            continue;
        }
        if(task == 3)
        {
            print_min_in_maxHeap(arr_max, size);
            print_avg_in_minHeap(arr_min, size);
        }
    }

    return 0;
}