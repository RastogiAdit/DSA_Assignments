#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long 
#define MOD 1000000007

ull power(ull a, ull b)
{   
    ull v = 1;
    for(ull int i = 0; i<b ;i++)
    {
        v = (v*a)%MOD;
    }
    return v%MOD;
}

ull power1(ull x, ull y)
{
    ull temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return (temp * temp)%MOD;
    else
        return (x * (temp * temp)%MOD)%MOD;
}


int main()
{
    ull n;
    scanf("%lld",&n);

    ull *arr1 = (ull *)malloc(n*sizeof(ull));
    ull *arr2 = (ull *)malloc(n*sizeof(ull));
    for(ull i = 0; i<n ;i++){scanf("%lld",&arr1[i]);}
    for(ull i = 0; i<n ;i++){scanf("%lld",&arr2[i]);}

    ull ans = 1;

    for(ull i = 0; i<n ;i++)
    {
        ans = (ans*(power(arr1[i],arr2[i])))%MOD; 
    }

    printf("%llu\n",ans);



    return 0;
}