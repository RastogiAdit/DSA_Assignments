#include <iostream>
#include <vector>
using namespace std;

void dfs(int k, vector<int> a[], int vis[])
{
    if(!vis[k])
    {
        vis[k]=1;
        cout<<k<<" ";
        for(int i=0;i<a[k].size();i++)
        {
            if(!vis[a[k][i]])     
            {
                dfs(a[k][i], a, vis);
            }
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
    dfs(0, a, vis);
}



int main()
{

    int n;
    cin>>n;
    int t = n;
    vector<int> a[n+1];
    while(t--)
    {
        int p,q;
        cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    dfs_pre(n, 0, a);
    cout<<endl;
    dfs_pre(n, 0, a);
    cout<<endl;

    
    return 0;
}


