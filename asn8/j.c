#include <stdio.h>

int quick_sort(int arr[], int si, int ei, int k);
int partition(int arr[], int si, int ei);

int main()
{

    int n, k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    int ans = quick_sort(arr, 0, n-1, n-k);

    printf("%d\n",ans);

    return 0;
}


int quick_sort(int arr[], int si, int ei, int k)
{
    int p = partition(arr, si, ei);
    if(p == k)
    {
        return arr[p];
    }
    else if(p > k)
    {
        return quick_sort(arr, si, p-1, k);
    }
    else if(p < k)
    {
        return quick_sort(arr, p+1, ei, k);
    }

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

