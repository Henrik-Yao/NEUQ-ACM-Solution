#include<bits/stdc++.h>
using namespace std;

int n,m;
char mm[1010][1010];
int vis[1010][1010];
int cant[1010][1010];
int ans[10010];
int xx,yy,cnt,num;
int dd[4][2]={-1,0,1,0,0,-1,0,1};//保证当前x y不改变
bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)
    {
        return false;
    }
    else
    {
         return true;
    }

}
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int dx=x+dd[i][1];
        int dy=y+dd[i][0];
        if(check(dx,dy)&&mm[x][y]!=mm[dx][dy]&&!vis[dx][dy])
        {
            num++;
            vis[dx][dy]=cnt;
            dfs(dx,dy);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>mm[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>xx>>yy;
        xx--;
        yy--;
        if(!vis[xx][yy])
        {
            num=1;
            cnt++;
            vis[xx][yy]=cnt;
            dfs(xx,yy);
            ans[cnt]=num;
        }
        cout<<ans[vis[xx][yy]]<<endl;
    }
    return 0;
}
