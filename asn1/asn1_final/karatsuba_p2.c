#include <stdio.h>
#include <math.h>
#define ull unsigned long long

ull int split(ull int l, char n1[], char n2[])
{
    char a[1000];
    char b[1000];
    char c[1000];
    char d[1000];
    if(l == 1)
    {
        return ((n1[0]-'0')*(n2[0]-'0'));
    }
    ull int prod1= 0,prod2= 0,prod3= 0,prod4= 0,sum= 0,i;
    ull int p = 0, k = 0;
    for(i = 0; i<l ;i++)
    {
        if(i<l/2)
        {
            a[k] = n1[i];
            c[k] = n2[i];
            k++;
        }
        else
        {
            b[p] = n1[i];
            d[p] = n2[i];
            p++;
        }
    }
    a[k]='\0';
    b[p]='\0';
    c[k]='\0';
    d[p]='\0';
    prod1 = split(l/2,a,c);
    prod2 = split(l/2,b,d);
    prod3 = split(l/2,a,d);
    prod4 = split(l/2,b,c);
    sum = prod3+prod4;

    return (prod1*pow(10,l) + sum*pow(10,l/2) + prod2);
}

int main()
{
    char n1[1024];
    char n2[1024];
    scanf("%s",n1);
    scanf("%s",n2);
    ull int l=0;
    while(n1[l]!='\0')
    {
        l++;
    }
    ull int s = split(l, n1,n2);
    printf("%lld", s);


    return 0;
}