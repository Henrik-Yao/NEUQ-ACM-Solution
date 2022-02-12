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
void dfs(int l,int r,int L,int R) {
    if(l>r) return;
    int v=R;
    for(int i=L;i<=R;++i)
        if(a[r]==b[i]) {v=i;break;}
    cout<<a[r]<<" ";
    dfs(l,l+v-L-1,L,v-1);
    dfs(l+v-L,r-1,v+1,R);    
}
int main() {    
    // freopen("a.in","r",stdin);
    int n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int j=1;j<=n;++j) b[j]=read();
    dfs(1,n,1,n);
    return 0;
}