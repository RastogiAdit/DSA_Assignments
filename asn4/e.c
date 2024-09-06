#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long int 


void possible(ll n, ll k, ll l, ll r, char arr[], ll index, ll *count, ll sumDig, ll finalNum)
{
    //base case
    if(index == n)
    {
        if(sumDig == k && finalNum>=l && finalNum<=r)
        {
            (*count)++;
        }
        return;
    }

    if(arr[index] == '?')
    {
        for(int i = 0; i<=9 ;i++)
        {
            possible(n, k, l, r, arr, index+1, count, sumDig + i, finalNum*10 + i);
        }
    }  
    else
    {
        possible(n, k, l, r, arr, index+1, count, sumDig + arr[index] - '0', finalNum*10 + arr[index] - '0'); 
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
    getchar();
    scanf("%s",arr);
    ll count = 0;

    possible(n,k,l,r,arr,0,&count,0,0);

    printf("%d\n", count);

    return 0;
}