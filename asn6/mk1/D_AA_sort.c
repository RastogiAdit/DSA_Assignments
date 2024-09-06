#include <stdio.h>

void mergeSort(int arr[], int si, int ei, int k);
void merge(int arr[], int si, int ei);
void insertion_sort(int arr[], int si, int ei, int k);




int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    k = n/k;

    mergeSort(arr, 0, n-1, k);

    for(int i = 0; i<n ;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}



void mergeSort(int arr[], int si, int ei, int k)
{
    if(si >= ei)
    {
        return;
    }

    if(ei - si + 1 <= k)
    {
        insertion_sort(arr, si, ei, k);
        return;
    }
    
    int mid = (si+ei)/2;
    mergeSort(arr, si, mid, k);
    mergeSort(arr, mid+1, ei, k);
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

void insertion_sort(int arr[], int si, int ei, int k)
{
    for(int i = si; i<ei ;i++)
    {
        for(int j = i+1; j<=ei ;j++)
        {
            if(arr[i] >= arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
