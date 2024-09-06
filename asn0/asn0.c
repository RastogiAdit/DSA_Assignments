#include <stdio.h>


int main()
{
    char n1[1000];
    char n2[1000];
    char a1[2000000];
    scanf("%s", n1);
    scanf("%s", n2);
    
    int len1 = 0; 
    int len2 = 0;
    for(int i = 0; n1[i] != '\0' ;i++)
    {
        len1++;
    }
    for(int i = 0; n2[i] != '\0' ;i++)
    {
        len2++;
    }
    
    int itr1 = len1-1;
    int itr2 = len2-1;
    int carry = 0;

    int min;
    if(len1>=len2)
    {
        min = len2;
    }
    else
    {
        min = len1;
    }
    int i = 0;
    for(; i<min ;i++)
    {
        int sum = carry + n1[itr1] + n2[itr2] - 96;
        itr1--;
        itr2--;
        if(sum <=9)
        {
            a1[i] = sum;
            carry = 0;
        }
        else
        {
            a1[i] = sum - 10;
            carry = 1;
        }
    }
    if(itr1 == -1)
    {
        while(itr2 != -1)
        {
            int sum = carry + n2[itr2] - 48;
            itr2--;
            if(sum <=9)
            {
                a1[i++] = sum;
                carry = 0;
            }
            else
            {
                a1[i++] = sum - 10;
                carry = 1;
            }
        }
        if(carry == 1)
        {
            a1[i] = 1;
        } 
    }
    if(itr2 == -1)
    {
         while(itr1 != -1)
        {
            int sum = carry + n1[itr1] - 48;
            itr1--;
            if(sum <=9)
            {
                a1[i++] = sum;
                carry = 0;
            }
            else
            {
                a1[i++] = sum - 10;
                carry = 1;
            }
        }
        if(carry == 1)
        {
            a1[i++] = 1;
        }
    }
    i--;
    int mid = i/2;
    for(int j = 0; j<=i/2 ;j++)
    {
        char temp = a1[j];
        a1[j] = a1[i-j];
        a1[i-j] = temp;
    }
    a1[i+1] = '\0';
    printf("\n");
    for(int j = 0; j<=i ;j++)
    {
        printf("%d", a1[j]);
    }
    printf("\n");

   

    return 0;
}