#include <stdio.h>
#include <math.h>
#define ll long long int

ll power(ll a, ll b)
{
    ll ans = 1;
    while(b--)
    {
        ans *= a;
    }
    return ans;
}

ll digitSum(ll n)
{
    ll sum = 0;
    while(n!=0)
    {
        sum += n%10; 
        n /= 10;
    }
    return sum;
}

ll solvemin(ll m, ll k)
{
    ll start = power(10,m-1);
    ll end = power(10,m) - 1;
    while(end>=start)
    {
        if(digitSum(start) == k)
        {
            return start;
        }
        start ++;
    }
    return -1;
}

ll solvemax(ll m, ll k)
{
    ll start = power(10,m-1);
    ll end = power(10,m) - 1;
    while(end>=start)
    {
        if(digitSum(end) == k)
        {
            return end;
        }
        end --;
    }
    return -1;
}

int main()
{
    ll m,k;
    scanf("%lld",&m);
    scanf("%lld",&k);

    printf("%lld ", solvemin(m,k));
    printf("%lld\n", solvemax(m,k));


    return 0;
}