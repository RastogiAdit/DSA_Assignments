#include <stdio.h>

int main()
{
    char a[1001];
    char b[1001];

    //input
    scanf("%s", a);
    scanf("%s", b);

    int x[1001] = {0};
    int y[1001] = {0};
    int result[2002] = {0};

    int len_a = 0;
    int len_b = 0;

    //length
    while(a[len_a]!='\0')
    {
        len_a++;
    }
    while(b[len_b]!='\0')
    {
        len_b++;
    }
    //char int reverse
    for(int i = 0; i<len_a ;i++)
    {
        x[i] = a[len_a - 1 - i] - '0';
    }

    for(int i = 0; i<len_a ;i++)
    {
        y[i] = b[len_b - 1 - i] - '0';
    }
    //mul
    for(int i = 0; i<len_a ;i++)
    {
        for(int j = 0; j<len_b ;j++)
        {
            result[i+j] += x[i]*y[j];
        }
    }
    //carry
    for(int i = 0; i< len_a + len_b -1 ;i++)
    {
        result[i+1] += result[i]/10;
        result[i] %= 10; 
    }

    //fint 1st 0
    int startPrinting = len_a + len_b - 1;
    while(startPrinting>=0 && result[startPrinting] == 0)
    {
        startPrinting--;
    }
    //print
    if(startPrinting < 0)
    {
        printf("0");
    }
    else
    {
        for(int i = startPrinting;i>=0;i--)
        {
            printf("%d", result[i]);
        }
    }
    return 0;
}