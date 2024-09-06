//hunger games
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int num, int si, int ei)
{
    if(si>ei)
    {
        return -1;
    }
    int mid = (si+ei+1)/2;
    if(arr[mid] == num)
    {
        return mid;
    }
    else if(arr[mid] > num)
    {
        return binary_search(arr, num, si, mid-1);
    }
    else if(arr[mid] < num)
    {
        return binary_search(arr, num, mid+1, ei);
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    int num;
    scanf("%d", &num);
    int ans = binary_search(arr,num, 0, n-1);
    printf("%d\n", ans);
    free(arr);

    return 0;
}