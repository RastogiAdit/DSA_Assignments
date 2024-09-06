#include <stdio.h>
#define uc unsigned char

void radix_sort(uc arr[], int n, int k)
{
    uc bin[16][n];
    for(int i = 0; i<16 ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            bin[i][j] = NULL;
        }
    }

    // for(int i = 0; i<16 ;i++)
    // {
    //     for(int j = 0; j<n ;j++)
    //     {
    //         printf("%X ",bin[i][j]);
    //     }
    //     printf("\n");
    // }


    int divisor = 1;
    for(int i = 0; i<k ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            uc temp = arr[j];
            uc digit = (arr[j]/divisor)%16;
            for(int l = 0; l<n ;l++)
            {
                if(bin[digit][l] == NULL)
                {
                    bin[digit][l] = arr[j];
                    break;
                }
            }
        }
        divisor *= 16;
        int index = 0;
        for(int a = 0; a<n ;a++)
        {
            for(int b = 0; b<n ;b++)
            {
                if(bin[a][b] != NULL)
                {
                    arr[index++] = bin[a][b];
                    bin[a][b] = NULL;
                }
            }
        }
    }
}



int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    uc arr[n];

    for(int i = 0; i<n ;i++)
    {
        scanf("%x",&arr[i]);
    }

    radix_sort(arr, n, k);


    for(int i = 0; i<n ;i++)
    {
        printf("%X ",arr[i]);
    }
    printf("\n");
    return 0;
}