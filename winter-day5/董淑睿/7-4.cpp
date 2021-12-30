#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,a[_];
int main() {
    int n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int x=read();
    int l=1,r=n,ans=0,js=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(a[mid]<=x) l=mid+1,ans=mid;
        else r=mid-1;
        ++js;
    }
    if(a[ans]!=x) cout<<"-1\n";
    else cout<<ans-1<<"\n";
    cout<<js<<"\n";
    return 0;
}