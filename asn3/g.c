#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n ;i++){scanf("%d",&arr[i]);}


    int i = 0, j = n-1;
    int max = 0;
    int nom = arr[0];
    int psy = arr[n-1];
    int flag = 0;
    while(i<j)
    {
        if(nom == psy)
        {
            max = nom;
            flag = 1;
            i++;
            j--;
            nom += arr[i];
            psy += arr[j];
            continue;
        }
        else if(nom<psy)
        {
            i++;
            nom += arr[i];
            continue;
        }
        else
        {
            j--;
            psy += arr[j];
            continue;
        }
    }

    if(flag)
    {
        printf("%d\n", max);
    }
    else
    {
        printf("0\n");
    }


    free(arr);

    return 0;
}