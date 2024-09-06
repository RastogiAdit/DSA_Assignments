// FRONT 1 2 3 4 5 REAR

#include <stdio.h>
#define SIZE 1000000

int front_max = 500000;
int rear_max =  499999;
int max[SIZE];
int front_min = 500000;
int rear_min =  499999;
int min[SIZE];

void reset_queues()
{
    front_max = 500000;
    rear_max =  499999;
    front_min = 500000;
    rear_min =  499999;
}
int isEmpty()
{
    if(front_max > rear_max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push_rear_max(int x)
{
    if(rear_max < SIZE - 1)
    {
        rear_max++;
        max[rear_max] = x; 
    }
}
void push_front_max(int x)
{
    if(front_max > 0)
    {
        front_max--;
        max[front_max] = x; 
    }
}
int peek_rear_max()
{
    if(rear_max < SIZE)
    {
        return max[rear_max];
    }
    else
    {
        return -1;
    }
}
int peek_front_max()
{
    if(front_max >= 0)
    {
        return max[front_max];
    }
    else
    {
        return -1;
    }
}

void push_rear_min(int x)
{
    if(rear_min < SIZE - 1)
    {
        rear_min++;
        min[rear_min] = x; 
    }
}
void push_front_min(int x)
{
    if(front_min > 0)
    {
        front_min--;
        min[front_min] = x; 
    }
}
int peek_rear_min()
{
    if(rear_min < SIZE)
    {
        return min[rear_min];
    }
    else
    {
        return -1;
    }
}
int peek_front_min()
{
    if(front_min >= 0)
    {
        return min[front_min];
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, max_dif;
    scanf("%d %d",&n,&max_dif);
    int arr[n];
    for(int i = 0; i<n ;i++){scanf("%d",&arr[i]);}

    int count_ans = n;

    for(int w = 2; w <= n ;w++)
    {
        for(int i = 0; i<=n-w ;i++)
        {
            for(int j = i; j<i+w ;j++)
            {
                if(isEmpty())
                {
                    push_front_max(arr[j]);
                    push_front_min(arr[j]);
                    continue;
                }
                if(arr[j] <= peek_front_max())
                {
                    push_rear_max(arr[j]);
                }
                else
                {
                    push_front_max(arr[j]);
                }
                if(arr[j] >= peek_front_min())
                {
                    push_rear_min(arr[j]);
                }
                else
                {
                    push_front_min(arr[j]);
                }
            }
            int difference = peek_front_max() - peek_front_min();
            if(difference <= max_dif)
            {
                count_ans++;
            }
            reset_queues();
        }
    }

    printf("%d\n", count_ans);



    return 0;
}
