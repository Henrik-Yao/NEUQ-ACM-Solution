#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int cnt,fa[_],d[_];
int dfs(int u,int dep) {
    if(u==0) return 0;
    d[u]=dep;
    while(233) {
        int v=read();
        if(v) fa[v]=u;            
        if(dfs(v,dep+1)==0) break;
    }
    return 1;
}
void solve() {
    cnt=0;
    dfs(read(),1);
    int x,y=read();
    x=read(),y=read();
    if(d[x]<d[y]) swap(x,y);
    while(d[x]>d[y]) x=fa[x];
    
    x=fa[x],y=fa[y];
    while(x!=y) x=fa[x],y=fa[y];
    cout<<"1\n";
    return;
    printf("%d\n",x);
}
int main() {
    int T=read();
    while(T-->0) solve();
    return 0;
}