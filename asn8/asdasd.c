#include <stdio.h>
int main()
{
    int a;
    printf("in how many sub you are pass\n");
    printf("enter 1 for maths"); 
    printf("enter 2 for physics"); 
    printf("enter 3 for both");
    scanf("%d",& a);
    if(a==1||a==2)
    {
        printf(" you will get gift of rs 15");
    }
    else
    {
        printf("you will get gift of rs 45");
    }
    return 0;


}
