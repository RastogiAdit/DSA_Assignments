#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void bfs(vector <int> adj[], int vis[], int parent[], int s, int d)
{
    queue <int> q;
    vis[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
                parent[it]=node;
            }
        }
    }

    int var = d;
    stack <int> ans;
    while(parent[var] != -1)
    {
        ans.push(var);
        var = parent[var];
    }
    ans.push(s);
    
    while(!ans.empty())
    {
        int x = ans.top();
        cout<<x<<" ";
        ans.pop();
    }
    cout<<endl;
    
}

int main()
{
    int v,e,s,d;
    cin>>v>>e>>s>>d;
    vector <int> adj[v];
    int vis[v];
    int parent[v];
    for(int i=0;i<v;i++){parent[i]=-1;}
    for(int i=0;i<v;i++){vis[i]=0;}
    for(int i = 0; i<e ;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    bfs(adj, vis, parent, s, d);


    return 0;
}