#include <iostream>
#include <vector>
using namespace std;

void DFS_int(int node, vector <int> adj[], int vis[], int v)
{
    vis[node] = 1;
    // cout<<node<<" ";
    for(auto i : adj[node])
    {
        if(vis[i] == 0)
        {
            DFS_int(i, adj, vis,v);
        }
    }
}

void DFS(int node, vector <int> adj[], int vis[], int v)
{
    DFS_int(node, adj, vis,v);
    for(int i=0;i<v+1;i++){vis[i]=0;}
    cout<<endl;
}





int main()
{
    int v, e;
    cin>>v>>e;
    int t=e;
    vector<int> adj[v+1];
    int vis[v+1];
    for(int i=0;i<v+1;i++){vis[i]=0;}
    while(t--)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }      

    int connections = 0;

    for(int i = 1;i<=v;i++)
    {
        if(vis[i] == 0)
        {
            connections++;
            DFS_int(i, adj, vis, v);
        }
    }

    cout<<connections<<endl;

    return 0;
}