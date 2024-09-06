#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int *arr = (int *)malloc(n*sizeof(int));
    int sum = 0;
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",arr[i]);
    }
    
    
    free(arr);

    return 0;
}
