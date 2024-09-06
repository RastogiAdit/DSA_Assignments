#include <stdio.h>


int main()
{
    int r,c;
    scanf("%d",&r);
    scanf("%d",&c);

    char arr[r][c];
    
    for(int i = 0; i<r ;i++)
    {
        for(int j = 0; j<c ;j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }

    for(int i = r-2; i>=0 ;i--)
    {
        for(int j = 0; j<c ;j++)
        {
            if(arr[i][j] == '*')
            {
                for(int k = i+1; k<r ;k++)
                {
                    if(k == r-1 && arr[k][j] == '.')
                    {
                        char temp = arr[i][j];
                        arr[i][j] = arr[k][j];
                        arr[k][j] = temp;
                    }
                    if(arr[k][j] == 'o' || arr[k][j] == '*')
                    {
                        char temp = arr[i][j];
                        arr[i][j] = arr[k-1][j];
                        arr[k-1][j] = temp;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i<r ;i++)
    {
        for(int j = 0; j<c ;j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}