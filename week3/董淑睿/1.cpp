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
int n,m,k,vis[_],ok[_];
vector<int> G[_];
int main() {
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;++i) vis[read()+1]=1;
    for(int i=1;i<=k;++i) {
        int x=read()+1,y=read()+1;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int s=read()+1,d=read()+1;
    if(!vis[d]) {
        printf("The city %d is not safe!",d-1);
        return 0;
    }
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        ok[u]=1;
        for(auto v:G[u]) {
            if(!ok[v]) q.push(v);
        }
    }
    if(!ok[d]) printf("The city %d can not arrive safely!",d-1);
    else printf("The city %d can arrive safely!",d-1);
    return 0;
}