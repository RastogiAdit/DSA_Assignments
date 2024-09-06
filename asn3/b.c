#include <stdio.h>


int cons_troops(char *arr, int n)
{
    int data[26];
    for(int i = 0; i<26 ;i++)
    {
        data[i] = -1;
    }
    data[arr[0] - 'a'] = 0;
    int length = 1;
    int max = 1;

    for(int i = 1; i<n ;i++)
    {
        int temp = data[arr[i] - 'a'];
        if(temp == -1 || i - length > temp)
        {
            length ++;
        }
        else 
        {
            if(length > max)
            {
                max = length;
            }
            length = i - temp;
        }
        data[arr[i] - 'a'] = i;
    }
    if(length > max)
    {
        max = length;
    }
    return max;
}


int main()
{
    int n;
    scanf("%d",&n);

    char arr[100001];
    scanf("%s",arr);
    
    int ans = cons_troops(arr, n);
    printf("%d\n",ans);


    return 0;
}