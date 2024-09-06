#include <stdio.h>

void solve(int n, int k, int arr[], int *ans, int sum)
{
    if(sum <= k)
    {
        //base case
        if(n == 0)
        {
            if(sum == k)
            {
                (*ans)++;
            }
            return;
        }

        solve(n, k, arr, ans, sum + arr[0]);
        solve(n-1, k, arr+1, ans, sum);
    }
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){scanf("%d",&arr[i]);}

    int ans = 0;

    solve(n,k,arr,&ans,0);

    printf("%d",ans);

    return 0;
}