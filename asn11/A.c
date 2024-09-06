#include <stdio.h>

int main()
{
    int n;
    unsigned int p;
    scanf("%d %d",&n,&p);

    int arr[n][n];
    int ans[n][n];
    int mul[n][n];
    

    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            scanf("%d",&arr[i][j]);
            mul[i][j] = arr[i][j];
            ans[i][j] = arr[i][j];
        }
    }


    for(int z = 1; z<p ;z++)
    {
        for(int i = 0; i<n ;i++)
        {
            for(int j = 0; j<n ;j++)
            {
                int sum = 0;
                for(int k = 0; k<n ;k++)
                {
                    sum += (arr[i][k]*mul[k][j]);
                }
                ans[i][j] = sum;
            }
        }
    }

    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    

    return 0;
}