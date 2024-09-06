#include <stdio.h>

void heapify(int arr[], int n, int i);
void heap_sort(int arr[], int n);


int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+1];
    arr[0] = -1;

    for(int i = 1; i<=n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i = n/2; i>0 ;i--)
    {
        heapify(arr, n, i);
    }
    heap_sort(arr, n);

    for(int i = 1; i<=n ;i++)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}

void heapify(int arr[], int n, int i)  //max heap
{
    int largest = i;
    int leftNode = 2*i;
    int rightNode = 2*i + 1;

    if(leftNode <= n && arr[largest] < arr[leftNode])
    {
        largest = leftNode;
    }
    if(rightNode <= n && arr[largest] < arr[rightNode])
    {
        largest = rightNode;
    }

    if(largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    int size = n;

    while(size > 1)
    {
        int temp = arr[size];
        arr[size] = arr[1];
        arr[1] = temp;
        size--;
        heapify(arr, size, 1);
    }
}
