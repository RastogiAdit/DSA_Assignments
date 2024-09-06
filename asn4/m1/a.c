#include <stdio.h>
#define ll long long

int size_num(ll n)
{
    int count = 0;
    while(n!=0)
    {
        count++;
        n /= 10;
    }
    if(count == 0)
    {
        return 1;
    }
    else
    {
        return count;
    }
}

void print_3(ll n)
{
    if(size_num(n) == 1)
    {
        switch(n)
        {
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
        }
    }
    if(size_num(n) == 2)
    {
        ll one_place = n%10;
        ll tens_place = n/10;
        switch(tens_place)
        {
            case 1:
                printf("ten ");
                break;
            case 2:
                printf("twenty ");
                break;
            case 3:
                printf("thirty ");
                break;
            case 4:
                printf("fourty ");
                break;
            case 5:
                printf("fifty ");
                break;
            case 6:
                printf("sixty ");
                break;
            case 7:
                printf("seventy ");
                break;
            case 8:
                printf("eighty ");
                break;
            case 9:
                printf("ninety ");
                break;
        }
        print_3(one_place);
    }
    if(size_num(n) == 3)
    {
        ll last2 = n%100;
        ll hund_place = n/100;
        switch(hund_place)
        {
            case 1:
                printf("one hundred ");
                break;
            case 2:
                printf("two hundred ");
                break;
            case 3:
                printf("three hundred ");
                break;
            case 4:
                printf("four hundred ");
                break;
            case 5:
                printf("five hundred ");
                break;
            case 6:
                printf("six hundred ");
                break;
            case 7:
                printf("seven hundred ");
                break;
            case 8:
                printf("eight hundred ");
                break;
            case 9:
                printf("nine hundered ");
                break;
        }  
        print_3(last2);      
    }
}



void print_all(ll n)
{
    if(n == 0)
    {
        printf("zero ");
    }
    else if(size_num(n)<=3)
    {
        print_3(n);
    }
    else if(size_num(n) <= 6)
    {
        ll int next = n/1000;
        print_all(next);
        printf("thousand ");
        next = n%1000;
        print_all(next);
    }
    else if(size_num(n) <= 9)
    {
        ll int next = n/1000000;
        print_all(next);
        printf("million ");
        next = n%1000000;
        print_all(next); 
    }
    else if(size_num(n) <= 12)
    {
        ll int next = n/1000000000;
        print_all(next);
        printf("billion ");
        next = n%1000000000;
        print_all(next); 
    }
}



int main()
{
    ll n;
    scanf("%lld", &n);

    print_all(n);

    

    return 0;
}