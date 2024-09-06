#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void prims(int n, int node, vector<pair <int,int> > adj[], int key[], int mst[], int parent[])
{
    int min = 0;
    for(int i = 1; i<n+1 ;i++)
    {
        if(key[i] < min)
        {
            min = i;
        }
    }
    mst[min] = 1;
    for(auto it : adj[min])
    {
        int node = it.first;
        int len = it.second;
        if(len < key[it])
        {
            key[it] = len;
        }
        key[it] = len;
        parent[it] = min;
    }
}

int main()
{
    int n;
    cin>>n;
    vector <pair<int, int>> adj[n+1];
    int t = n;
    while(t--)
    {
        int p,q,r;
        cin>>p>>q>>r;
        adj[p].push_back(make_pair(q,r));
        adj[q].push_back(make_pair(p,r));
    }

    int key[n+1], mst[n+1], parent[n+1];
    for(int i=0;i<n+1;i++){mst[i]=0;parent[i]=-1;key[i]=INT_MAX;}
    key[1]=0;

    prims(n, 1, adj);

    return 0;
}