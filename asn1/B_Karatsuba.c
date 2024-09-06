#include<stdio.h>
#include<string.h>
void karatsuba(char n1[], char n2[], char p[]);

int main ()
{
    char num1[100000];
    char num2[100000];
    char prod[100000];
    scanf("%s",num1);
    scanf("%s",num2);
    
    karatsuba(num1, num2, prod);
 
    

    return 0;

}

void karatsuba(char n1[], char n2[], char p[])
{

}