#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m;
struct node {
    int v,nxt,q;
}e[_<<1];
int head[_],tot;
void add(int u,int v,int q) {
    e[++tot].v=v;
    e[tot].nxt=head[u];
    e[tot].q=q;
    head[u]=tot;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>> >q;
int dis[_],vis[_],pre[_];
void dfs(int u) {
    if(!pre[u]) return;
    dfs(pre[u]);
    cout<<"-->"<<u-1;
}
void dij(int S) {
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0;
    q.push(make_pair(0,S));
    while(!q.empty()) {
        pair<int,int> u=q.top();
        q.pop();
        if(dis[u.second]!=u.first) continue;
        for(int i=head[u.second];i;i=e[i].nxt) {
            int v=e[i].v;
            if(dis[v]>dis[u.second]+e[i].q) {               
                dis[v]=dis[u.second]+e[i].q;
                pre[v]=u.second;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
int main() {
    n=read(),m=read()/2;
    for(int i=1;i<=m;++i) {
        int u=read()+1,v=read()+1,q=read();
        add(u,v,q),add(v,u,q);
    }
    int S=read()+1,T=read()+1;
    cout<<S-1;
    dij(S);
    dfs(T);
    if(S==T) {
        cout<<"-->"<<T-1;
    }
    cout<<":"<<dis[T]<<"\n";
    return 0;
}
