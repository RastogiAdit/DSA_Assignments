#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2;
    scanf("%d",&n1);
    scanf("%d",&n2);
    int *arr1 = (int *)malloc(n1*sizeof(int));
    int *arr2 = (int *)malloc(n2*sizeof(int));

    for(int i = 0; i<n1 ;i++)
    {
        scanf("%d",&arr1[i]);          
    }
    for(int i = 0; i<n2 ;i++)
    {
        scanf("%d",&arr2[i]);  
    }

    int i=0,j=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            printf("%d ",arr1[i]);
            i++;
            continue;
        }
        printf("%d ",arr2[j]);
        j++;
    }
    if(i == n1)
    {
        while(j<n2)
        {
            printf("%d ",arr2[j]);
            j++;
        }
    }
    else if(j == n2)
    {
        while(i<n1)
        {
            printf("%d ",arr1[i]);
            i++;
        }
    }






    free(arr1);
    free(arr2);
    return 0;
}