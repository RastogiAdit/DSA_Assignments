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

    int sum = 0;
    int max = 0;

    for(int i = 0; i<n ;i++)
    {
        for(int count = 0; count < n-i ;count++) 
        {
            for(int j = count+i; j>=i ;j--)
            {
                sum += arr[j];
            }
            if(sum >= max)
            {
                max = sum;
            }
            sum = 0;
        }
    }

    printf("%d\n",max);

    free(arr);
}