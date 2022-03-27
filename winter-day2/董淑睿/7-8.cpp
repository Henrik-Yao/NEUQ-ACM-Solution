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
int n,a[_],ls[_],rs[_],ans,cnm;
void dfs(int u,int dep) {
    if(a[ls[u]]) dfs(ls[u],dep+1);
    ans=max(ans,dep);
    ++cnm;
    if(cnm==1) cout<<a[u];
    else cout<<" "<<a[u];
    if(a[rs[u]])dfs(rs[u],dep+1);
}
int main() {
    // freopen("a.in","r",stdin);
    int T=read();
    while(T-->0) {
        ans=0;
        n=read();
        for(int i=1;i<=n;++i) a[i]=read();
        for(int i=1;i<=n;++i) ls[i]=i<<1,rs[i]=i<<1|1;
        for(int i=1;i<=n;++i) {
            if(ls[i]>n) ls[i]=0;            
            if(rs[i]>n) rs[i]=0;
        }
        cnm=0;
        dfs(1,1);
        cout<<"\n"<<ans<<"\n";
    }
    return 0;
}