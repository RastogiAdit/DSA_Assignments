#include <stdio.h>

int main()
{
    // char a = '5';
    // char b = '2';
    // int ans = ((a-'0')*2);
    // printf("%d", ans);
    char n1[1000];
    scanf("%s",n1);

    char b = '5';
    printf("%d\n", (b - '0')*3);

    for(int i = 0; i <3 ;i++)
    {
        printf("%c\n",n1[i]);
    }
    printf("\n");

    return 0;
}