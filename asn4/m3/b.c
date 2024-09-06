#include <stdio.h>

int solve(int n, int k, int arr[], int dist[], int index)
{
    //base case
    if(index == n)
    {
        int max = 0;
        for(int i = 0; i<k ;i++)
        {
            if(dist[i] > max)
            {
                max = dist[i];
            }
        }
        return max; 
    }


    int ans = 1e6;

    for(int i = 0; i<k ;i++)
    {
        dist[i] += arr[index];
        int maxVal = solve(n,k,arr,dist,index+1);

        if(maxVal < ans)
        {
            ans = maxVal;
        }

        dist[i] -= arr[index];
    }
    return ans;
}


int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    int dist[k];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i<k ;i++)
    {
        dist[i] = 0;
    }

    int ans = solve(n,k,arr,dist,0);

    printf("%d\n",ans);

    return 0;
}
