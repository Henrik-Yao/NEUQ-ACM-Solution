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
}a[_];
bool cmp(node a,node b) {
    return a.q<b.q;
}
int f[_];
int find(int x) {
    return f[x]==x ?  x : f[x]=find(f[x]);
}
void uu(int x,int y) {
    x=find(x),y=find(y);
    f[x]=y;
}
int main() {
    while(cin>>n>>m) {
        for(int i=1;i<=m;++i) {
            a[i].u=read();
            a[i].v=read();
            a[i].q=read();
        }
        sort(a+1,a+1+m,cmp);
        for(int i=1;i<=n;++i) f[i]=i;
        int tot=0;
        for(int i=1;i<=m;++i) {
            int u=a[i].u,v=a[i].v;
            if(find(u)!=find(v)) {
                uu(u,v);
                tot+=a[i].q;
            }
        }
        for(int i=2;i<=n;++i) {
            if(find(i)!=find(i-1)) {
                tot=-1;break;
            }
        }
        if(tot!=-1)
            cout<<tot<<"\n";
        else
            cout<<"There is no minimum spanning tree.\n";
    }
    return 0;
}   