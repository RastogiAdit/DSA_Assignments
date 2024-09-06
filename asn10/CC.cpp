#include <iostream>
#include <vector>
using namespace std;

int dfs(int node, vector <int> adj[], int vis[], int depth, int sum, int n)
{
    vis[node] = 1;
    sum = depth;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            sum += dfs(it, adj, vis, depth, sum, n);
        }
    }
    for(auto it : adj[node])
    {
        vis[it] = 0;
    }
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            sum += dfs(it, adj, vis, depth+1, sum, n);
        }
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    vector <int> adj[n+2];
    int vis[n+2];
    for(int i = 0; i<n+2 ;i++)
    {
        vis[i] = 0;
    }
    for(int i = 0;i<n;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }   

    int ans = dfs(1, adj, vis, 0, 0, n);
    cout<<ans<<endl;

    return 0;
}