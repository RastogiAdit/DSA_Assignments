#include <stdio.h>


void codeleet(int n, int k, int rate[], int time[], int index,  int *ans, int rating, int samay)
{
    //base case
    if(index == n)
    {   
        if(samay<=k)
        {
            if(rating > (*ans))
            {
                (*ans) = rating;
            }
        }
        return;
    }

    //nhi lia
    codeleet(n, k, rate, time, index+1, ans, rating, samay);

    //le lia
    codeleet(n, k, rate, time, index+1, ans, rating+rate[index], samay+time[index]);



}


int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int rate[n];
    int time[n];
    for(int i=0;i<n;i++){scanf("%d",&rate[i]);}
    for(int i=0;i<n;i++){scanf("%d",&time[i]);}

    int ans = 0;

    codeleet(n, k, rate, time, 0, &ans, 0, 0);

    printf("%d\n", ans);

    return 0;
}