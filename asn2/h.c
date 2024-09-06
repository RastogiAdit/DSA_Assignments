#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n*sizeof(int));

    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    int diff = 0;
    int max = 0;

    for(int i = 0; i<n ;i++)
    {
        for(int j = i; j<n ;j++)
        {
            diff = arr[j] - arr[i];
            if(diff>=max)
            {
                max = diff;
            }
        }
    }

    printf("%d\n",max);

    free(arr);


    return 0;
}