#include<stdio.h>

void solve(int n,int a,int b){
    if(a==0&&b==0)
    {
        printf(" ");
        return;
    }
    char ans[n];
    int av=a/(b+1);
    int s=a%(b+1);
    int i=0;
    while(i<n)
    {
        if(s)
        {
            ans[i++]='K';
            s--;
        }
        for(int j=0;j<av;j++)
        {
            ans[i++]='K';
        }
        if(b)
        {
            ans[i++]='O';
            b--;
        }
    }
    printf("%s",ans);
}

int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    solve(n,a,b);
}