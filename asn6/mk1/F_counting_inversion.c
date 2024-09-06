#include <stdio.h>

void mergeSort(int arr[], int si, int ei);
void merge(int arr[], int si, int ei);

int count = 0;




int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("%d\n", count);

    return 0;
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
        if(arr1[index1] <= arr2[index2])
        {
            arr[i++] = arr1[index1++];
        }
        else
        {
            count += (mid - index1 + 1); //WHY????
            arr[i++] = arr2[index2++];
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
