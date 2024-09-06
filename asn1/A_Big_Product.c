#include <stdio.h>

void big_product(char n1[], char n2[], int prod[]);
void small_product(char n1[], int s, int ans[]);
void add(int a[], int b[]);

int main()
{
    char n1[1000];
    char n2[1000];
    int prod[1000000];
    prod[0] = -1;
    scanf("%s", n1);
    scanf("%s", n2);
    big_product(n1, n2, prod);
    for(int i = 0;prod[i] != -1 ;i++) 
    {
        printf("%d",prod[i]);
    }
    printf("\n");
    
    return 0;
}

void big_product(char n1[], char n2[], int prod[])
{
    int len2 = 0;
    for(int i = 0; n2[i] != '\0' ;i++)
    {
        len2++;
    }
    len2--;
    int i;
    int cross = 0;
    for(i = len2; i>=0 ;i--)
    {
        int sum[1001];
        small_product(n1, (int)(n2[i] - '0'), sum);
        int len_sum;
        for(int j = 0; j<1001 ;j++)
        {
            if(sum[j] == -1)
            {
                len_sum = j;
                break;
            }
        }
        for(int j = 0; j<cross ;j++)
        {
            sum[len_sum + j] = 0;
        }
        if(cross != 0)
        {
            sum[len_sum + cross] = -1;
        }
        cross++;
        
        add(prod, sum);
    }
}
void small_product(char n1[], int s, int ans[])
{
    int len = 0;
    for(int i = 0; n1[i] != '\0' ;i++)
    {
        len++;
    }
    int carry = 0;
    int itr = len-1; 
    int i;
    int itr_a = 0;
    for(i = itr; i>=0 ;i--)
    {
        int prod = ((n1[itr]-'0')*s) + carry;
        itr--;
        if(prod<=9)
        {
            carry = 0;
            ans[itr_a] = prod;
            itr_a++;
        }
        else
        {
            carry = prod/10;
            ans[itr_a] = prod%10;
            itr_a++;
        }
    }
    if(carry != 0)
    {
        ans[itr_a] = carry;
        itr_a++;
    }
    itr_a--;
    for(int i = 0; i<=itr_a/2 ;i++)
    {
        int temp = ans[i];
        ans[i] = ans[itr_a - i];
        ans[itr_a - i] = temp;
    }
    itr_a++;
    if(itr_a != 1001)
    {
        ans[itr_a] = -1;
    }
}
void add(int a[], int b[])
{
    int len1 = 0;
    int len2 = 0;
    int ans[1000000];
    for(int i = 0; a[i] != -1 ;i++)
    {
        len1++;
    }
    for(int i = 0; b[i] != -1 ;i++)
    {
        len2++;
    }
    int itr1 = len1-1;
    int itr2 = len2-1;
    int carry = 0;
    int min;
    if(len1>=len2){min = len2;}
    else{min = len1;}
    int i = 0;
    for(; i<min ;i++)
    {
        int sum = carry + a[itr1] + b[itr2];
        itr1--;
        itr2--;
        if(sum<=9)
        {
            ans[i] = sum;
            carry = 0;
        }
        else
        {
            ans[i] = sum - 10;
            carry = 1;
        }
    }
    if(itr1 == -1)
    {
        while(itr2 != -1)
        {
            int sum = carry + b[itr2];
            itr2--;
            if(sum <=9)
            {
                ans[i++] = sum;
                carry = 0;
            }
            else
            {
                ans[i++] = sum - 10;
                carry = 1;
            }
        }
        if(carry == 1)
        {
            ans[i] = 1;
        } 
    }
    if(itr2 == -1)
    {
         while(itr1 != -1)
        {
            int sum = carry + a[itr1];
            itr1--;
            if(sum <=9)
            {
                ans[i++] = sum;
                carry = 0;
            }
            else
            {
                ans[i++] = sum - 10;
                carry = 1;
            }
        }
        if(carry == 1)
        {
            ans[i++] = 1;
        }
    }
    i--;
    int mid = i/2;
    for(int j = 0; j<=i/2 ;j++)
    {
        char temp = ans[j];
        ans[j] = ans[i-j];
        ans[i-j] = temp;
    }
    ans[i+1] = -1;
    for(int j = 0; j<=i+1 ;j++)
    {
        a[j] = ans[j];
    }
}
