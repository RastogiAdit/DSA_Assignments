#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int DFS_int(int node, vector <int> adj[], int vis[], int v, stack <int>& st, int inStack[])
{
    vis[node] = 1;
    inStack[node] = 1;

    for(auto i : adj[node])
    {
        if(vis[i] == 0)
        {
            if(DFS_int(i, adj, vis, v, st, inStack))
            {
                return 1;
            }
        }
        else if(inStack[i])
        {
            return 1;
        }
    }
    
    inStack[node] = 0;
    st.push(node);
    return 0;
}

int DFS(vector <int> adj[], int vis[], int v, stack <int>& st)
{
    int inStack[v + 1];
    for(int i = 0;i<v+1;i++){inStack[i]=0;}
    for(int i = 1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(DFS_int(i, adj, vis,v, st, inStack))
            {
                return 1;
            }
        }
    }
    while(!st.empty())
    {
        int x = st.top();
        cout<<x<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector <int> adj[v+1];
    stack <int> st;
    int vis[v+1];
    for(int i = 0;i<v+1;i++){vis[i]=0;}
    for(int i = 0; i<e ;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }

    if(DFS(adj, vis, v, st))
    {
        cout<<"IMPOSSIBLE"<<endl;
    }

    
    

    return 0;
}