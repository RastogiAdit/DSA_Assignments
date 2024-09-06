#include <stdio.h>
#define l long
l int karatsuba(l int x, l int y);
l int power(l int a, l int b);

int main()
{
    l int x,y;
    scanf("%ld %ld", &x, &y);
    l int prod = karatsuba(x,y);
    printf("%ld\n",prod);

    return 0;
}

l int karatsuba(l int x, l int y)
{
    if(x<=9 && y<=9)
    {
        return x*y;
    }
    l int dum1 = x;
    l int dum2 = y;
    l int len = 0;
    while(dum1 != 0)
    {
        dum1 /= 10;
        len++;
    }
    l int n = len/2;
    l int a = x/(power(10,n));
    l int b = x%(power(10,n));
    l int c = y/(power(10,n));
    l int d = y%(power(10,n));
    l int p = a+b;
    l int q = c+d;
    l int ac = karatsuba(a,c);
    l int bd = karatsuba(b,d);
    l int pq = p*q;
    l int ad_plus_bc = pq - ac - bd;
    return (power(10, len)*ac  +  power(10,n)*ad_plus_bc  +  bd);
}

l int power(l int a, l int b)
{
    l int ans = 1;
    for(int i = 0; i<b ;i++)
    {
        ans *= a;
    }
    return ans;
}