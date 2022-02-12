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
    node(int x=0,int y=0,int c=0) {u=x,v=y,q=c;}
    int u,v,q;
    bool operator < (const node &b) const {
        return q<b.q;
    }
}e[_];
int f[_],S;
int find(int x) {
    return f[x]==x ? x : f[x]=find(f[x]);
}
int main() {
    // freopen("a.in","r",stdin);
    while(cin>>n>>S>>m) {
        S++;
        for(int i=1;i<=m;++i) {
            int x=read()+1,y=read()+1,q=read();
            e[i]=node(x,y,q);
        }
        sort(e+1,e+1+m);
        vector<int> A,B;
        for(int i=1;i<=m;++i) {            
            int u=e[i].u,v=e[i].v;
            if(u==S||v==S) A.push_back(i),B.push_back(i);
        }
        B.push_back(-1);
        int mi=0x3f3f3f3f;
        for(auto x:A) {
            for(int j=1;j<=n+1;++j) f[j]=j;
            f[e[x].u]=e[x].v;
            // cout<<"debug: \n";
            // cout<<e[x].u<<" "<<e[x].v<<"\n";
            for(auto y:B) if(x!=y) {
                int tot=e[x].q,cnt=1;
                if(y!=-1) f[find(e[y].u)]=find(e[y].v),cnt++,tot+=e[y].q;//,cout<<e[y].u<<" "<<e[y].v<<"\n";;
                for(int i=1;i<=m;++i) {
                    int u=e[i].u,v=e[i].v;
                    if(u==S||v==S) continue;
                    if(find(u)!=find(v)) {
                        // cout<<e[i].u<<" "<<e[i].v<<"\n";
                        ++cnt;
                        tot+=e[i].q;
                        f[find(u)]=find(v);
                    }
                }
                if(cnt==n-1) {
                    mi=min(mi,tot);
                }
            }
        }
        // cout<<"cnm";
        if(mi==0x3f3f3f3f) cout<<"-1\n";
        else cout<<mi<<"\n";
    }
    return 0;
}