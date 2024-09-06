#include <stdio.h>
#include <stdlib.h>
#define ll long long

int count_setbits(int n)
{
    int count = 0;
    while(n!=0)
    {
        if(n&1LL)
        {
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0;

    for(int i = 0; i<n-k+1 ;i++)
    {
        int temp_or = 0;
        for(int j = i; j<i+k ;j++)
        {
            temp_or = temp_or | arr[j];
        }
        int temp_ans = count_setbits(temp_or);
        if(temp_ans > max){max = temp_ans;}
    }

    printf("%d\n", max);




    free(arr);

    return 0;
}