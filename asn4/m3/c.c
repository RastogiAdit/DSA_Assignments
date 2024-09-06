#include <stdio.h>


void solve(int n, int k, int rate[], int time[], int *ans, int samay, int index, int rating)
{
    //base case
    if(index == n)
    {
        if(samay <= k)
        {
            if(rating > (*ans))
            {
                (*ans) = rating;
            }
        }
        return;
    }


    //le lia
    solve(n,k,rate,time,ans,samay + time[index],index+1, rating + rate[index]);
    //nhi lia
    solve(n,k,rate,time,ans,samay,index+1,rating);
}



int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int rate[n];
    int time[n];
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&rate[i]);
    }
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&time[i]);
    }

    int ans = 0;
    solve(n,k,rate,time,&ans,0,0,0);

    printf("%d",ans);

    return 0;
}