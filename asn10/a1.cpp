#include <iostream>
#include <vector>
using namespace std;

void dfs(int node , vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector <int> dfsOnGraph(int n, vector<int> adj[])
{
    int vis[n+1];
    for(int i = 0; i<n+1 ;i++)
    {
        vis[i] = 0;
    }
    int start = 0;
    vector<int> ls;

    dfs(start, adj, vis, ls);
    return ls;
}

int main()
{
    int n;
    cin>>n;
    vector <int> adj[n+1];

    for(int i = 0; i<n ;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector <int> ans = dfsOnGraph(n, adj);
    for(auto it : ans)
    {
        cout<<ans[it]<<" ";
    }
    cout<<endl;

    return 0;
}