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
int a[1010],b[101],ls[234],rs[234];
int dfs(int l,int r,int L,int R) {
    if(l>r) return -1;
    int v=L;
    for(int i=L;i<=R;++i)
        if(a[l]==b[i]) {v=i;break;}
    ls[l]=dfs(l+1,l+v-L,L,v-1);    
    rs[l]=dfs(l+v-L+1,r,v+1,R);    
    return l;
}
int main() {    
    // freopen("a.in","r",stdin);
    int n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int j=1;j<=n;++j) b[j]=read();
    dfs(1,n,1,n);
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u=q.front();
        cout<<a[u]<<" ";
        q.pop();
        if(ls[u]!=-1) q.push(ls[u]);
        if(rs[u]!=-1) q.push(rs[u]);
    }
    return 0;
}