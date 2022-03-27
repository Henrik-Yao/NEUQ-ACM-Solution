#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
char mm[1005][1005];
int vis[1005][1005];
int cant[1005][1005];
int ans[10005];
int xx,yy,cnt,num;
int dd[4][2]={-1,0,1,0,0,-1,0,1};
bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n)
    return false;
    return true;
}
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int dx=x+dd[i][1],dy=y+dd[i][0];
        if(check(dx,dy)&&!vis[dx][dy]&&mm[x][y]!=mm[dx][dy])
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
        scanf("%s",mm[i]);
    }
    while(m--)
    {
        scanf("%d%d",&xx,&yy);
        xx--,yy--;
        if(!vis[xx][yy])
        {
            cnt++;
            num=1;
            vis[xx][yy]=cnt;
            dfs(xx,yy);
            ans[cnt]=num;
        }
        cout<<ans[vis[xx][yy]]<<endl;
    }
    return 0;
}

