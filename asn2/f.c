//how to becomne a milloinaire
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, q;
    scanf("%d %d",&s, &q);
    int *arr = (int *)malloc(s*sizeof(int));

    for(int i = 0; i<s ;i++)
    {
        scanf("%d", &arr[i]);
    }

    while(q--)
    {
        int s,e;
        scanf("%d %d", &s, &e);
        int sum = 0;
        for(int i = s-1; i<=e-1 ;i++)
        {
            sum += arr[i];
        }
        printf("%d\n", sum);
    }

    free(arr);

    return 0;
}