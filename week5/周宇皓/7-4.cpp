#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
int g[2005][2005];
bool vis[2005][2005];
int dx[4][2]={0,1,0,-1,1,0,-1,0};
void bfs(int x,int y)
{
    queue<pii> q;
    vis[x][y]=1;
    q.push({x,y});
    while(!q.empty())
    {
        pii a=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ix=a.first+dx[i][0],iy=a.second+dx[i][1];
            if(ix<0||ix>=n||iy<0||iy>=m)
            continue;
            if(g[ix][iy]==1&&!vis[ix][iy])
            {
                vis[ix][iy]=1;
                q.push({ix,iy});
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        scanf("%d",&g[i][j]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j]&&g[i][j]==1)
            {
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
