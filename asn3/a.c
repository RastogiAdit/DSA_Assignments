#include <stdio.h>

int is_palin(char arr[], int si, int ei);

int main()
{
    int n;
    scanf("%d", &n);
    char arr[3000];
    scanf("%s", arr);

    int temp = 1;
    int ans = 1;
    int i = 0;
    int j = n-1;
    while(i<j)
    {
        if(is_palin(arr, i, j))
        {
            temp = j-i+1;
            if(temp>ans){ans = temp;}
            i++;
            j=n-1;
        }
        else
        {
            j--;
        }
        if(i==j)
        {
            i++;
            j = n-1;
        }
    }

    printf("%d\n", ans);

    return 0;
}


int is_palin(char arr[], int si, int ei)
{
    for(int i = si, j = ei; j>=i ;i++, j--)
    {
        if(arr[i] != arr[j])
        {
            return 0;
        }
    }
    return 1;
}