#include<stdio.h>
#define max(a,b) a>b?a:b

void solve(int n,int k,int* weights,int*ans,int sum){
    if(sum<=k)
    {
        if(n==0)
        {
            if(sum==k)
            {
                (*ans)++;
            }
        return;
        }
        solve(n,k,weights,ans,sum+weights[0]);
        solve(n-1,k,weights+1,ans,sum);
        return;
    }
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int weights[n];
    for(int i=0;i<n;i++){
        scanf("%d",&weights[i]);
    }
    int ans=0;
    solve(n,k,weights,&ans,0);
    printf("%d",ans);
    return 0;
}