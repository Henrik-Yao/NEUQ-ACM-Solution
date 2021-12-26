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
int n,m,f[_],q;
int find(int fa) {
    return f[fa]==fa? fa : f[fa]=find(f[fa]);
}
int main() {
    // freopen("a.in","r",stdin);
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;++i) f[i]=i;
    for(int i=1;i<=m;++i) {
        int x=read(),y=read();
        x=find(x),y=find(y);
        f[x]=y;
    }
    while(q-->0) {
        int x=read(),y=read();
        if(find(x)==find(y)) cout<<"In the same gang.\n";
        else cout<<"In different gangs.\n";
    }
    set<int> dsr;
    for(int i=1;i<=n;++i) dsr.insert(find(i));
    cout<<dsr.size();
    return 0;
}