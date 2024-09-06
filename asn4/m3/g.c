#include <stdio.h>
#include <string.h>


int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b,a%b);

}


char* findLCM(char* a, char* b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    int LCMlen  = (lenA*lenB)/gcd(lenA,lenB); 

    char lcm[1000001];

    for(int i = 0; i<LCMlen ;i++)
    {
        lcm[i] = a[i%lenA];
        if(lcm[i] != b[i%lenB])
        {
            return "-1";
        }
    }
    lcm[LCMlen] = '\0';
    return lcm;
}


int main()
{
    char a[1000001], b[1000001];

    scanf("%s",a);
    scanf("%s",b);

    printf("%s\n",findLCM(a,b));

    return 0;
}