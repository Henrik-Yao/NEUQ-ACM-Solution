#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7,N=1021;
const int fx[4]={-1,1,0,0},fy[4]={0,0,1,-1};
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m,a[N][N],vis[N][N],f[_],siz[_];
int id(int x,int y) {return n*(x-1)+y;}
int find(int x) {return x==f[x] ? x : f[x]=find(f[x]);}
void uu(int x,int y) {
    x=find(x),y=find(y);
    if(find(x)==find(y)) return;
    siz[x]+=siz[y];
    f[y]=x;
}
void work(int x,int y) {
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        pair<int,int> tmp=q.front();
        q.pop();
        if(vis[tmp.first][tmp.second]==1) continue;
        vis[tmp.first][tmp.second]=1;
        for(int i=0;i<=3;++i) {
            int nx=tmp.first+fx[i],ny=tmp.second+fy[i];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=n) {
                if(vis[nx][ny]==0&&(a[tmp.first][tmp.second]!=a[nx][ny])) {
                    uu(id(tmp.first,tmp.second),id(nx,ny));
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            f[id(i,j)]=id(i,j);
            siz[id(i,j)]=1;
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(!vis[i][j]) work(i,j);
        }
    }
    while(m-->0) {
        int x=read(),y=read();
        cout<<siz[find(id(x,y))];
        if(m!=0) cout<<"\n";
    }
    return 0;
}