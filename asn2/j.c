#include <stdio.h>

int n;

void fill(int r, int c, int sn, int arr[n][n], int size)
{
    if(size == 0){return;}
    if(size == 1)
    {
        arr[r][c] = sn;
        return;
    }
    for(int i = c; i<=c+size-1 ;i++)
    {
        arr[r][i] = sn;
        sn++;
    }
    for(int i = r+1; i<=r+size-1 ;i++)
    {
        arr[i][c+size-1] = sn;
        sn++;
    }
    for(int i = c+size-2; i>=c ;i--)
    {
        arr[r+size-1][i] = sn;
        sn++;
    }
    for(int i = r+size-2; i>=r+1 ;i--)
    {
        arr[i][c] = sn;
        sn++;
    }
    fill(r+1,c+1,sn,arr,size-2);

}



int main()
{

    scanf("%d", &n);

    int arr[n][n];
    fill(0,0,1,arr,n);
    for(int i = 0; i<n ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return 0;
}