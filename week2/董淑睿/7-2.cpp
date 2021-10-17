#include <bits/stdc++.h>
using namespace std;
const int _=1e5;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m,k,vis[_];
struct node {
    int v,nxt;
}e[_<<2];
int head[_],tot;
void add(int u,int v) {
    e[++tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=m;++i) {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    k=read();
    while(k-->0) {
        int num=read();
        for(int i=1;i<=n;++i) vis[i]=0;
        for(int i=1;i<=num;++i) vis[read()]=1;
        int flag=1;
        for(int i=1;i<=n;++i) {
            if(vis[i]) continue;
            for(int j=head[i];j;j=e[j].nxt) {
                int v=e[j].v;
                if(!vis[v]) {
                    flag=0;break;
                }
            }
            if(!flag) break;
        }
        puts(flag==1?"YES":"NO");
    }
    return 0;
}