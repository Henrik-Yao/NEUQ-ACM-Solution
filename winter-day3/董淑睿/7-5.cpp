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
int n,m;
struct node {
    int u,v,q;
    bool operator < (const node &b) const {
        return q<b.q;
    }
}e[_];
int f[_];
int find(int x) {
    return f[x]==x ? x : f[x]=find(f[x]);
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=m;++i) {
        e[i].u=read();
        e[i].v=read();
        e[i].q=read();
    }
    sort(e+1,e+1+m);
    int tot=0,ma=-101001,cnt=0;
    for(int i=1;i<=n;++i) f[i]=i;
    for(int i=1;i<=m;++i) {
        int u=find(e[i].u),v=find(e[i].v);
        if(cnt==n-1) break;
        if(u!=v) {
            ++cnt;
            tot+=e[i].q;
            ma=max(ma,e[i].q);
            f[u]=v;
        }
    }
    cout<<n-1<<" "<<ma;
    return 0;
}