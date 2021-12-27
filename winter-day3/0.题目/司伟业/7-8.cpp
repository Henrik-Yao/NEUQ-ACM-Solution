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
vector<int> G[_];
int n,m,ru[_],dep[_];
void solve() {
    for(int i=1;i<=n;++i) {
        ru[i]=dep[i]=0;
        G[i].clear();
    }
    for(int i=1;i<=m;++i) {
        int x=read(),y=read();
        G[x].push_back(y);
        ru[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;++i) {
        if(!ru[i]) q.push(i);
    }
    int tmp=0,cnt=0;
    while(!q.empty()) {
        if(q.size()>=2) tmp=1;
        int u=q.front();
        q.pop();
        cnt++;
        for(auto v:G[u]) {
            ru[v]--;
            if(ru[v]==0) {
                q.push(v);
                
            }
        }
    }
    if(cnt!=n) cnt=0;
    else cnt=1+tmp;
    cout<<cnt<<"\n";
}
int main() {
    // freopen("a.in","r",stdin);
    while(cin>>n>>m) solve();
    return 0;
}