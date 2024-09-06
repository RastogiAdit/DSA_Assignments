//Final Destination
#include <stdio.h>
#include <stdlib.h>

int can_jump(int * arr, int num, int si, int ei);

int main()
{
    int s;
    scanf("%d", &s);
    int n;
    scanf("%d", &n);

    int * arr = (int *)malloc((s*s)*sizeof(int));

    for(int i = 0; i<s*s ;i++)
    {
        scanf("%d", &arr[i]);
    }

    if(can_jump(arr, n, 0, s*s-1))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    free(arr);

    return 0;
}

int can_jump(int * arr, int num, int si, int ei)
{
    if(si>ei)
    {
        return 0;
    }
    int mid = (si+ei+1)/2;

    if(arr[mid] == num)
    {
        return 1;
    }
    else if(arr[mid] > num)
    {
        return can_jump(arr, num, si, mid-1);
    }
    else
    {
        return can_jump(arr, num, mid+1, ei);
    }

}