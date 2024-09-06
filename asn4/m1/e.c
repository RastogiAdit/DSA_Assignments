#include <stdio.h>
#define ull unsigned long long
// #include <string.h>

int sumDig(ull n, ull k)
{   
    ull sum = 0;
    while(n != 0)
    {
        ull temp = n%10;
        sum += temp;
        n /= 10;
    }
    if(sum == k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int size_num(ull n)
{
    int count = 0;
    while(n!=0)
    {
        count++;
        n /= 10;
    }
    if(count == 0)
    {
        return 1;
    }
    else
    {
        return count;
    }
}

int isSame(char str[], ull i, ull n)
{
    if(size_num(i) != n)
    {
        return 0;
    }
    int flag = 1;
    for(int i = n-1; i>=0 ;i--)
    {
        int temp = i%10;
        if(temp != (str[i]-'0') && str[i] != '?')
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ull n,k,l,r;
    scanf("%llu",&n);
    scanf("%llu",&k);
    scanf("%llu",&l);
    scanf("%llu",&r);

    char str[100];
    scanf("%s", str);

    int count = 0;

    for(ull i = l; i<=r ;i++)
    {
        if(sumDig(i,k))
        {
            if(isSame(str, i, n))
            {
                count++;
            }
        }
    }

    printf("%d\n", count);
    

    return 0;
}