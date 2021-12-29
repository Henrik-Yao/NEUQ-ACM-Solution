#include<bits/stdc++.h>
using namespace std;
int n,m;
int dao[109][109];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int vis[109][109];
bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    return true;
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int dx=x+dir[i][0],dy=y+dir[i][1];
        if(check(dx,dy)&&vis[dx][dy]==0&&dao[dx][dy]==1)
        {
            dfs(dx,dy);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&dao[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&dao[i][j]==1)
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
