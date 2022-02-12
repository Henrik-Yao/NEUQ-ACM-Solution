#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int ma,n,a[_],w[_];
vector<int> G[_];
int dfs(int &x,int &cnt) {
    if(a[x]==0) return 0;
    int u=++cnt;
    w[u]=a[x];
    int S=dfs(++x,cnt);
    if(S) {
        G[u].push_back(S);
        // cout<<u<<"->"<<S<<"\n";
    }
    int T=dfs(++x,cnt);
    if(T) {
        G[u].push_back(T);
        // cout<<u<<"->"<<T<<"\n";
    }
    return u;
}
int vis[_],tot[_];
void f(int u,int dep) {
    if(G[u].empty()) {
        vis[dep]=1;
        tot[dep]+=w[u];
        return;
    }
    for(auto x:G[u]) f(x,dep+1);
}
int main() {
    // freopen("a.in","r",stdin);
    while(scanf("%d",&a[++n])!=EOF);
    int A=1,B=0;
    dfs(A,B);
    f(1,0);
    int id=-1;
    for(int i=0;i<=n;++i) {
        if(vis[i]) {
            if(id==-1) id=i;
            else if(tot[id]<=tot[i]) id=i;
        }
    }
    cout<<id<<"\n";
    return 0;
}