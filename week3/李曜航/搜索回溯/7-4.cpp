
#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int n,m;
char a[1005][1005];
int fa[1005*1005*4],ans[1005*1005*4];
int sx[4] = {1,-1,0,0};
int sy[4] = {0,0,1,-1};

int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return find(fa[x]);
}
void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if(x!=y){ans[x] += ans[y];fa[y] = fa[x];}
}
int dfs(int x, int y)
{
    if(fa[x*n+y]!=-1) return find(x*n+y);
    fa[x*n+y]=x*n+y,ans[x*n+y]=1;//initial

    for(int i=0;i<=3;i++)
    {
        int nowx = x+sx[i], nowy = y+sy[i];//上下左右
        if(nowx>=1&&nowx<=n&&nowy>=1&&nowy<=n)
        {
            if(a[nowx][nowy]!=a[x][y])
            {
                merge(x*n+y,dfs(nowx,nowy));   
            }
        }
    }
    return find(x*n+y);
}
int main()
{
    // freopen("P1141_1.in","r",stdin);
    n = read(), m = read();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<a[i][j];
    //     }
    //     cout<<endl;
    // }
    memset(fa,-1,sizeof(fa));
    while(m--)
    {
        int x = read(), y = read();
        // vis[x][y] = true;
        cout<<ans[dfs(x,y)]<<endl;
    }
}