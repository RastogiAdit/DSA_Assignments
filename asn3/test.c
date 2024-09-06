#include<stdio.h>
#define ll long long


int count_setbits(ll n)
{
    int count = 0;
    while(n!=0)
    {
        if(n&1LL)
        {
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main ()
{
    printf("%d", count_setbits(10));

    return 0;

}