#include <iostream>
#include <vector>
using namespace std;

int subTree(int node, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    int currSize = 1;
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            currSize += subTree(it, adj, vis);
        }
    }
    return currSize;
}

int sol(vector <int> adj[], int n, int vis[])
{
    for(int i=1; i<n+1 ;i++)
    {
        int flag = 1;
        for(auto it : adj[i])
        {
            for(int j = 1; j <= n; j++) 
            {
                vis[j] = 0;
            }
            int x = subTree(it, adj, vis);
            if(x >= n/2)    
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector <int> adj[n+1];
    int vis[n+1];
    for(int i = 0; i<n+1 ;i++)
    {
        vis[i] = 0;
    }
    for(int i = 0;i<n-1;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }

    int val = sol(adj, n, vis);
    cout<<val<<endl;

    return 0;
}