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
int n,m,S,T,ok[_],vis[_],f[_],ru[_];
vector<int> GG[2][_],G[_];
void init(int S,int t) {
    queue<int> q;
    q.push(S);
    for(int i=1;i<=n;++i) ok[i]=0;
    ok[S]=1;
    while(!q.empty()) {
        int u=q.front();q.pop();
        vis[u]++;
        for(auto v:GG[t][u]) {
            if(!ok[v]) ok[v]=1,q.push(v);
        }
    }
}
int dsr[_];
void dfs(int u) {
    if(dsr[u]||u==T) return;
    dsr[u]=1;
    for(auto v:GG[0][u]) dfs(v);
    if(GG[0][u].empty())
        if(u!=T) {puts("No");exit(0);}
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=m;++i) {
        int x=read(),y=read();
        GG[0][x].push_back(y);
        GG[1][y].push_back(x);
    }
    S=read(),T=read();
    init(S,0);
    int flag_1=0;
    for(int i=1;i<=n;++i) flag_1+=(vis[i]==1);
    init(T,1);   
    int flag_2=0;
    for(int i=1;i<=n;++i) flag_2+=(vis[i]==2);
    for(int u=1;u<=n;++u)
        for(auto v:GG[0][u])
            if(vis[u]==2&&vis[v]==2) {
                G[u].push_back(v);
                ru[v]++;
            }
    queue<int> q;
    q.push(S);
    f[S]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto v:G[u]) {
            f[v]+=f[u];
            ru[v]--;
            if(!ru[v]) q.push(v);
        }
    }
    cout<<f[T]<<" ";
    dfs(S);puts("Yes");
    return 0;
}
