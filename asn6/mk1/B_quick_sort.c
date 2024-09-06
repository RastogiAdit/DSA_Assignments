#include <stdio.h>

void quick_sort(int arr[], int si, int ei);
int partition(int arr[], int si, int ei);

int main()
{

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    quick_sort(arr, 0, n-1);

    for(int i = 0; i<n ;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}


void quick_sort(int arr[], int si, int ei)
{
    if(si >= ei)
    {
        return;
    }

    int p = partition(arr, si, ei);
    quick_sort(arr, si, p-1);
    quick_sort(arr, p+1, ei);

}



int partition(int arr[], int si, int ei)
{
    int count = 0;
    for(int i = si+1; i<=ei ;i++)
    {
        if(arr[i] <= arr[si])
        {
            count++;
        }
    }
    int temp = arr[si];
    arr[si] = arr[si+count];
    arr[si+count] = temp;

    int j = ei;

    for(int i = si; i<si+count ;i++)
    {
        if(arr[i] > arr[si+count])
        {
            for(; j>si+count ;j--)
            {
                if(arr[j] <= arr[si+count])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }
    }
    return si+count;
}

