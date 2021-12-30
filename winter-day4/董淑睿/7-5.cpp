#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=2e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
struct node{
    int c,val;
    bool operator < (const node &b) const {
        return val>b.val;
    }
};
struct edge{
    int nxt,v,q;
}G[_<<1];
int n,m,tot,head[_],sx,sy,tx,ty;
int P[_],V[_],d[_],f[1005][1005];
int fx[5]={0,1,0,-1,0};
int fy[5]={0,0,1,0,-1};
priority_queue<node>q;
int F(int x,int y) {return x*m+y;}

void add(int from,int v,int q) {
    G[++tot].nxt=head[from];
    G[tot].v=v;
    G[tot].q=q;
    head[from]=tot;
}

void dij() {
    memset(d,0x3f,sizeof(d));
    q.push((node){F(sx,sy),0});d[F(sx,sy)]=0;
    while(q.size()) {
        node u=q.top();q.pop();
        if(V[u.c]) continue;
        V[u.c]=1;
        for(int i=head[u.c];i;i=G[i].nxt) {
            int v=G[i].v;
            if(d[v]>d[u.c]+G[i].q) {
                d[v]=d[u.c]+G[i].q;
                q.push((node){v,d[v]});
                P[v]=u.c;
            }
        }
    }
    int x=F(tx,ty);
    while(1) {
        cout<<"("<<x/m<<" "<<x%m<<")";
        if(x==F(sx,sy)) break;
        x=P[x];
    }
}

int main() {
    m=read(),n=read(),sx=read(),sy=read(),tx=read(),ty=read();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) f[i][j]=read();
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(f[i][j]==-1) continue;
        for(int k=1;k<=4;k++) {
            int x=i+fx[k],y=j+fy[k];
            if(x>=0&&y>=0&&f[x][y]!=-1&&x<n&&y<m) {
                int tmp_x=F(x,y),tmp_y=F(i,j);
                add(tmp_y,tmp_x,f[x][y]),add(tmp_x,tmp_y,f[i][j]);
            }
        }
    }
    dij();
    return 0;
}
