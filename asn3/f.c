#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, x;
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &x);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;

    while(j<k)
    {
        sum+=arr[j];
        j++;
    }
    j--;
    while(j<n)
    {
        if(sum/k >= x)
        {
            ans++;
        }
        sum -= arr[i];
        i++;
        j++;
        if(j<n)
        {
            sum += arr[j];
        }
    }

  
    printf("%d",ans);

    free(arr);
    return 0;
}