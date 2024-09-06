#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int grid[500][500];
int vis[500][500];

void BFS(int row, int col, int vis[500][500], int grid[500][500], int m, int n)
{
    vis[row][col] = 1;
    queue < pair <int,int> > q;
    q.push(make_pair(row,col));

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int nrow, ncol;
        nrow = row-1;
        ncol = col;

        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
        {
            vis[nrow][ncol] = 1;
            q.push(make_pair(nrow,ncol));
        }

        nrow = row;
        ncol = col+1;
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
        {
            vis[nrow][ncol] = 1;
            q.push(make_pair(nrow,ncol));
        }

        nrow = row+1;
        ncol = col;
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
        {
            vis[nrow][ncol] = 1;
            q.push(make_pair(nrow,ncol));
        }

        nrow = row;
        ncol = col-1;
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
        {
            vis[nrow][ncol] = 1;
            q.push(make_pair(nrow,ncol));
        }
    }

}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i = 0; i<m ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i<m ;i++)
    {
        grid[i][n] = -1;
    }

    for(int i = 0; i<n ;i++)
    {
        grid[m][i] = -1;
    }

    for(int i = 0; i<m ;i++)
    {
        for(int j = 0; j<n ;j++)
        {
            vis[i][j] = 0;
        }
    }

    int count = 0;

    for(int row = 0; row<m ;row++)
    {
        for(int col = 0; col<n ;col++)
        {
            if(!vis[row][col] && grid[row][col] == 1)
            {
                count++;
                BFS(row,col,vis,grid,m,n);
            }
        }
    }

    cout<<count<<endl;

    return 0;
}