#include<stdio.h>
int power(int a,int b){
    int product=1;
    for(int i=0;i<b;i++){
        product*=a;
    }
    return product;
}

int digitSum(int n){
    int sum=0;
    while(n!=0){
        sum=sum+n%10;
        n=n/10;
    }
    return sum;
}

int solvemax(int m,int k){
    int end=power(10,m)-1;
    int start=power(10,m-1);
    while(end>=start){
        //printf("%d\n",end);
        if(digitSum(end)==k){
            return end;
        }
        end--;
    }
    return -1;
}

int solvemin(int m,int k){
    int end=power(10,m)-1;
    int start=power(10,m-1);
    while(start<=end){
        if(digitSum(start)==k){
            return start;
        }
        start++;
    }
    return -1;
}

int main(){
    int m,k;
    scanf("%d %d",&m,&k);
    printf("%d ",solvemin(m,k));
    printf("%d",solvemax(m,k));
}