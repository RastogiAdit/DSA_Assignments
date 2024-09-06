//Root for Nom
#include <stdio.h>
#define u unsigned
#define ld long double

u int find_left(u int n, u int s, u int e);
ld root(u int n, u int l, u int s, u int e);

int main()
{
    u int num;
    scanf("%u",&num);

    u int left = find_left(num, 1, num);
    ld ans = root(num, left, 0, 999999);
    printf("%Lf\n", ans);

    return 0;
}


u int find_left(u int n, u int s, u int e)
{
    u int mid = (s+e)/2;
    if(n == 0)
    {
        return 0;
    }
    if(mid*mid <= n && (mid+1)*(mid+1)>n)
    {
        return mid;
    }
    else if(mid*mid > n)
    {
        return find_left(n, s, mid-1);
    }
    else
    {
        return find_left(n, mid+1, e);
    }
}

ld root(u int n, u int l, u int s, u int e)
{
   u int mid = (s+e)/2;
    if(n == 0)
    {
        return (ld)0;
    }

    ld a = ((ld)mid/1000000 + (ld)l);
    ld b = ((ld)(mid+1)/1000000 + (ld)l);

    if(a*a <= (ld)n && b*b>(ld)n)
    {
        return a;
    }
    else if(a*a > (ld)n)
    {
        return root(n, l, s, mid-1);
    }
    else
    {
        return root(n, l, mid+1, e);
    }
}