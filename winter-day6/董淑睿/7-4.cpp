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
int sum[_],n,a[_],lsh[_];
int lowbit(int x) {return x&-x;}
void add(int pos,int val) {
    for(int i=pos;i<=n;i+=lowbit(i)) sum[i]+=val;
}
int query(int x) {
    int tot=0;
    for(int i=x;i;i-=lowbit(i)) tot+=sum[i];
    return tot;
} 
int main() {
    n=read();
    for(int i=1;i<=n;++i) lsh[i]=a[i]=read();
    sort(lsh+1,lsh+1+n);
    int len=unique(lsh+1,lsh+1+n)-lsh-1;
    for(int i=1;i<=n;++i) a[i]=lower_bound(lsh+1,lsh+1+len,a[i])-lsh;
    ll tot=0;
    for(int i=1;i<=n;++i) {
        tot+=i-1-query(a[i]);
        add(a[i],1);
    }
    cout<<tot<<"\n";
    return 0;
}