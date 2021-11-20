#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
int g[2010][2010];
bool vis[2010][2010];
int co[4][2]={0,1,0,-1,1,0,-1,0};

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
            int ix=a.first+co[i][0];
            int iy=a.second+co[i][1];
            if(ix<0||ix>=n||iy<0||iy>=m)
            continue;
            if((g[ix][iy]==1)&&(!vis[ix][iy]))
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
            if((!vis[i][j])&&(g[i][j]==1))
            {
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
