#include <stdio.h>
#include <string.h>
#define ll long long int


void solve(ll n, ll k, ll l, ll r, char arr[], int *ans, int index, ll sumDig, ll number)
{
    //base case
    if(index == n)
    {
        if(sumDig == k && number >= l && number <= r)
        {
            (*ans)++;
        }
        return;
    }


    if(arr[index] == '?')
    {
        for(int i = 0; i<=9 ;i++)
        {
            solve(n,k,l,r,arr,ans,index+1,sumDig + i, number*10 + i);
        }
    }
    else
    {
        solve(n,k,l,r,arr,ans,index+1,sumDig + arr[index] - '0', number*10 + arr[index] - '0');
    }
}




int main()
{
    ll n,k,l,r;
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%lld",&l);
    scanf("%lld",&r);

    char arr[n];

    scanf("%s",arr);

    int ans = 0;

    solve(n,k,l,r,arr,&ans,0,0,0);

    printf("%d", ans);

    return 0;
}