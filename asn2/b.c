//Peanut Butter Summit
#include <stdio.h>
#include <stdlib.h>

int find_peak(int *arr, int si, int ei, int size)
{
    if(size == 0)
    {
        return -1;
    }
    if(size == 1)
    {
        return 1;
    }
    if(size == 2)
    {
        if(arr[0]>arr[1])
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if(si>ei)
    {
        return -1;
    }
    int mid = (si+ei+1)/2;
    
    if(mid == 0)
    {
        if(arr[1]>arr[0] && arr[1]>arr[2])
        {
            return 2;
        }
        else if(arr[0]>arr[1])
        {
            return 1;
        }
    }

    if(mid == size-1)
    {
        if(arr[size-2]>arr[size-1] && arr[size-2]>arr[size-3])
        {
            return size-2+1;
        }
        else if(arr[size-1]>arr[size-2])
        {
            return size-1+1;
        }
    }


    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
    {
        return mid+1;
    }
    else if(arr[mid]<arr[mid+1])
    {
        return find_peak(arr, mid+1, ei, size);
    }
    else if(arr[mid]<arr[mid-1])
    {
        return find_peak(arr, si, mid-1, size);
    }
    return -1;

}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));

    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    int ans = find_peak(arr, 0, n-1, n);
    printf("%d", ans);

    free(arr);

    return 0;
}