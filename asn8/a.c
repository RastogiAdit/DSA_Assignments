#include <stdio.h>
#define SIZE 100000

int top = -1;
char arr[SIZE];
void push(char x);
void pop();
char peek();
int isEmpty();


int main()
{
    char arr_temp[SIZE];
    scanf("%s",arr_temp);
    int size = 0;
    while(arr_temp[size] != '\0')
    {
        size++;
    }

    for(int i = 0; i<size ;i++)
    {
        if((arr_temp[i] == '[') || (arr_temp[i] == '{') || (arr_temp[i] == '('))
        {
            push(arr_temp[i]);
        }
        else
        {
            char c = arr_temp[i];
            if(!isEmpty())
            {
                char p = peek();
                if((p == '(' && c == ')') || (p == '{' && c == '}') || (p == '[' && c == ']'))
                {
                    pop();
                }
                else
                {
                    printf("NO\n");
                    return 0;
                }
            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    if(isEmpty())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

void push(char x)
{
    if(top < SIZE - 1)
    {
        top++;
        arr[top] = x;
    }
}
void pop()
{
    if(top != -1)
    {
        top--;
    }
}
char peek()
{
    if(top != -1)
    {
        return arr[top];
    }
    return 'x';
}
int isEmpty()
{   
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
