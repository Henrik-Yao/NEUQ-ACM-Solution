#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int m,n,cnt;
const int N = 2010;
int sx[5] = {0,0,1,-1};
int sy[5] = {1,-1,0,0};
bool mp[N][N], vis[N][N];
void dfs(int x, int y)
{
    for(int i=0;i<4;i++)
    {
        int nx = sx[i]+x, ny = sy[i]+y;
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&& mp[nx][ny] && !vis[nx][ny])
        {
            vis[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}
int main()
{
    n = read(), m = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[i][j] = read();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]&&!vis[i][j])
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;

}