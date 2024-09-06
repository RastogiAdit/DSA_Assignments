#include <stdio.h>
#include <string.h>
#define SIZE 100000

int top = -1;
char arr[SIZE];

void push(char x);
void pop();
int empty();
int peek();

void sub(char arr1[], int s1, char arr2[], int s2, int ans[]);




int main()
{   
    int n,k;
    scanf("%d %d",&n,&k);
    char num[n];
    scanf("%s",num);
    int temp_k = k;
    for(int i = 0; i<n ;i++)
    {
        if(top == -1)
        {
            // printf("\nHOLA1\n");
            if(num[i] != '0')
            {
                push(num[i]);
                // printf("\nHOLA2\n");
            }
        }
        else
        {
            // printf("\nHOLA3\n");
            if(peek() >= num[i])
            {
                while(peek() >= num[i] && temp_k>0)
                {
                    // printf("\nHOLA3\n");
                    pop();
                    temp_k--;
                }
                if(top == -1 && num[i] == '0')
                {}
                else
                {
                    push(num[i]);
                }
            }
            else
            {
                // printf("\nHOLA4\n");
                push(num[i]);
            }
        }
    }

    char num2[n];
    int size_num2 = 0;
    int index = 0;
    while(top != -1)
    {
        num2[index++] = peek();
        size_num2++;
        pop();
    }

    int ans[n];


    for(int i = 0; i<size_num2/2 ;i++)
    {
        char temp = num2[i];
        num2[i] = num2[size_num2 - i - 1];
        num2[size_num2 - i - 1] = temp;
    }
 
    sub(num, n, num2, size_num2, ans);

    for(int i = 0; i<n;i++)
    {
        printf("%d",ans[i]);
    }
    printf("\n");
    

    return 0;
}

void sub(char arr1[], int s1, char arr2[], int s2, int ans[])
{
    int index1 = s1-1;
    int index2 = s2-1;
    int index3 = s1-1;
    while(index2 >= 0)
    {
        int a1 = (int)arr1[index1];
        int b1 = (int)arr2[index2];
        if(a1 >= b1)
        {
            ans[index3] = a1 - b1;
            index1--;
            index2--;
            index3--;
        }
        else
        {
            ans[index3] = a1 - b1 + 10;
            index1--;
            index2--;
            index3--;
        }
    }
    while(index1 >=0)
    {
        int a1 = (int)arr1[index1];
        ans[index3] = a1 - 48;
        index1--;
        index3--;
    }
}


void push(char x)
{
    if(top != SIZE -1)
    {
        top++;
        arr[top] = x;
    }
    else
    {
        printf("Stack Full\n");
    }
}

void pop()
{
    if(top != -1)
    {
        top--;
    }
    else
    {
        printf("Stack Empty\n");
    }
}


int empty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int peek()
{
    if(top != -1)
    {
        return arr[top];
    }
    else
    {
        return -1;
    }
}