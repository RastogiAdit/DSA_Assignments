#include <stdio.h>
#include <math.h>

void quick_sort(int arr[], int si, int ei, int n, int depth);
int partition(int arr[], int si, int ei);

void mergeSort(int arr[], int si, int ei);
void merge(int arr[], int si, int ei);



int main()
{

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    int depth = 1;

    quick_sort(arr, 0, n-1, n, depth);

    for(int i = 0; i<n ;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}


void quick_sort(int arr[], int si, int ei, int n, int depth)
{
    if(si >= ei)
    {
        return;
    }

    if(depth >= 2*log(n))
    {
        mergeSort(arr, si, ei);
        return;
    }

    int p = partition(arr, si, ei);
    quick_sort(arr, si, p-1, n, depth+1);
    quick_sort(arr, p+1, ei, n, depth+1);

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

void mergeSort(int arr[], int si, int ei)
{
    if(si >= ei)
    {
        return;
    }
    
    int mid = (si+ei)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, ei);
}

void merge(int arr[], int si, int ei)
{
    int mid = (si+ei)/2;
    int len1 = mid - si + 1;
    int len2 = ei - mid;

    int arr1[len1];
    int arr2[len2];

    int j = si;

    for(int i = 0; i<len1 ;i++)
    {
        arr1[i] = arr[j++];
    }
    for(int i = 0; i<len2 ;i++)
    {
        arr2[i] = arr[j++];
    }

    int index1 = 0;
    int index2 = 0;
    int i = si;

    while(index1 != len1 && index2 != len2)
    {
        if(arr1[index1] >= arr2[index2])
        {
            arr[i++] = arr2[index2++];
        }
        else if(arr1[index1] < arr2[index2])
        {
            arr[i++] = arr1[index1++];
        }
    }
    while(index1 != len1)
    {
        arr[i++] = arr1[index1++];
    }
    while(index2 != len2)
    {
        arr[i++] = arr2[index2++];
    }
}
