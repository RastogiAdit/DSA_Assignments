#include <stdio.h>
int n = 9;

int isSafe(int row, int col, int arr[n][n])
{
    int temp1[10];
    int temp2[10];
    int temp3[10];
    for(int i = 0; i<10 ;i++)
    {
        temp1[i] = 1;
        temp2[i] = 1;
        temp3[i] = 1;
    }
    temp1[0] = 0;
    temp2[0] = 0;
    temp3[0] = 0;

    for(int i = 0; i<9 ;i++)
    {
        if(arr[row][i] != -1)
        {
            temp1[arr[row][i]] = 0;
        }
        if(arr[i][col] != -1)
        {
            temp2[arr[i][col]] = 0;
        }
        if(arr[3*(row/3) + i/3][3*(col/3) + i%3] != -1)
        {
            temp3[arr[3*(row/3) + i/3][3*(col/3) + i%3]] = 0;
        }
    }
    int count = 0;
    int ans;
    for(int i = 1; i<=9 ;i++)
    {
        if(temp1[i] && temp2[i] && temp3[i]) 
        {
            count++;
            ans = i;
        }  
    }
    if(count == 1)
    {
        return ans;
    }
    else
    {
        return 0;
    }
}

void solve(int arr[n][n])
{ 
    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            if(arr[i][j] == -1)
            {
                int val = isSafe(i, j, arr);
                if(val != 0)
                {
                    arr[i][j] = val;
                }  
            }
        }
    } 

    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            if(arr[i][j] == -1)
            {
                solve(arr);
            }
        }
    }

}


int main()
{
    int arr[n][n];

    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    solve(arr);

    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}