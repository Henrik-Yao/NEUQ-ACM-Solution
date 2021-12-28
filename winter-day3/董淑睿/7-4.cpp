#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m,a[200][200],vis[201][201];
int fx[]={0,0,-1,1};
int fy[]={1,-1,0,0};
void dfs(int x,int y) {
    vis[x][y]=1;
    for(int i=0;i<4;++i) {
        int nx=x+fx[i],ny=y+fy[i];
        if(vis[nx][ny]==0&&a[nx][ny]&&1<=nx&&nx<=n&&1<=ny&&ny<=m) {
            dfs(nx,ny);
        }
    }
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read();
    int cnt=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i][j]&&vis[i][j]==0) dfs(i,j),cnt++;
        }
    }
    cout<<cnt;
    return 0;
}