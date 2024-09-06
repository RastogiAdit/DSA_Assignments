#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    char arr[n];
    scanf("%[^\n]", arr);

    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] != ' ')
        {
            j++;
            continue;
        }
        for (int k = j - 1; k >= i; k--)
        {
            printf("%c", arr[k]);
        }
        printf(" ");
        j++;
        i = j;
    }
    for (int k = j - 1; k >= i; k--)
    {
        printf("%c", arr[k]);
    }

    return 0;
}