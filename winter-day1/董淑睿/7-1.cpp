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
int n,q;
ll s[_];
void add(int x,int ad) {
    for(int i=x;i<=n;i+=(i&(-i))) s[i]+=ad;
}
ll sum(int x) {
    ll ans=0;
    for(int i=x;i>0;i-=(i&(-i))) ans+=s[i];
    return ans;
}
int main() {
    // freopen("a.in","r",stdin);
    n=read(),q=read();
    for(int i=1;i<=n;++i) add(i,read());
    while(q-->0) {
        int opt=read(),x=read(),y=read();
        // cout<<opt<<" "<<x<<" "<<y<<"\n";
        if(opt==1) {
            add(x,y);
        } else {
            cout<<sum(y)-sum(x-1)<<"\n";
        }
    }
    return 0;
}