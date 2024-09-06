#include <stdio.h>

int f_vov(char a)
{
    if(a == 'a'){return 1;}
    if(a == 'e'){return 1;}
    if(a == 'i'){return 1;}
    if(a == 'o'){return 1;}
    if(a == 'u'){return 1;}
    return 0;
}


int main()
{   
    int n;
    scanf("%d\n", &n);

    char arr[n];
    scanf("%[^\n]", arr);

    int i = 0;
    int j = n-1;
    
    while(i<j)
    {
        if(f_vov(arr[i]) && f_vov(arr[j]))
        {
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else if(f_vov(arr[i]))
        {
            j--;
        }
        else if(f_vov(arr[j]))
        {
            i++;
        }
        else
        {
            i++;
            j--;
        }
    }

    printf("%s",arr);


    return 0;
}