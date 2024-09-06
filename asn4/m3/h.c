#include <stdio.h>


void solve(int n, int a, int b)
{
    if(a == 0 && b == 0)
    {
        printf(" ");
        return;
    }

    char arr[n];

    int av = a/(b+1);
    int s = a%(b+1);
    int i = 0;
    while(i<n)
    {
        if(s)
        {
            arr[i++] = 'K';
            s--;
        }
        for(int j = 0; j<av ;j++)
        {
            arr[i++] = 'K';
        }
        if(b)
        {
            arr[i++] = 'O';
            b--;
        }
    }
    printf("%s", arr);


}




int main()
{
    int n,a,b;
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);

    solve(n,a,b);


    return 0;
}