#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
#define MOD 1000000007


ull isPrime(ull n)
{
    for(ull i = 2; i<=n/2 ;i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    } 
    return 1;
}


int main()
{
    int n;
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n ;i++){scanf("%d",&arr[i]);}

    int flag = 0;
    ull ans = 1;

    for(int i = 0; i<n ;i++)
    {
        if(isPrime(arr[i]))
        {
        }
        else
        {
            ans = (ans*arr[i])%MOD;
            flag = 1;
            continue;
        }
    }

    if(flag == 1){printf("%llu\n",ans);}
    else {printf("-1\n");}

    free(arr);
    

    return 0;
}