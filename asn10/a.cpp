#include <iostream>
#include <vector>
using namespace std;
int f_maxi = 1;
int maxi = 1;
int len = 0;

void dfs(int k, vector<int> a[], int vis[])
{
    if(!vis[k])
    {
        len++;
        vis[k]=1;
        // cout<<k<<" ";
        for(int i=0;i<a[k].size();i++)
        {
            if(!vis[a[k][i]])     
            {
                dfs(a[k][i], a, vis);
            }
        }
        if(len>maxi)
        {
            maxi = len;
            len--;
        }
        else
        {
            len--;
        }
    }
}

void dfs_pre(int n, int k, vector<int> a[])
{
    int vis[100];
    for(int i = 0; i<100 ;i++)
    {
        vis[i] = 0;
    }
    dfs(k , a, vis);
}

int Sol(int n, vector<int> a[])
{
    int i = n;
    while(i!=-1)
    {
        dfs_pre(n, i, a);
        if(maxi > f_maxi)
        {
            f_maxi = maxi;
        }
        maxi = 1;
        len = 0;
        i--;
    }
    return f_maxi;
}



int main()
{

    int n;
    cin>>n;
    vector<int> a[n+1];
    int t = n;
    while(t--)
    {
        int p,q;
        cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    int output = Sol(n, a);
    cout<<output<<endl;

    
    return 0;
}