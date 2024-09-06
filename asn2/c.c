//the legend of 7
#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int num;
    scanf("%d",&num);
    int *arr = (int *)malloc((num-1)*sizeof(int));
    for(int i = 0; i<num-1 ;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    if(arr[num-2] == 6)
    {
        printf("-1\n");
        return 0;
    }
    else if(arr[num-2]<6)
    {
        printf("%d\n",5 - arr[num-2]);
    }
    else if(arr[num-2] >=7)
    {
        printf("%d\n", num - arr[num-2] + 5);
    }

    free(arr);

    return 0;
}