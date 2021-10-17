#include <bits/stdc++.h>
using namespace std;
const int _=1e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,a[_],b[_];
void merge_sort(int l,int r) {
    if(l==r) return;
    int mid=(l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int x=l,y=mid+1;
    for(int i=l;i<=r;++i) {
        if(x<=mid&&y<=r) {
            if(a[x]<a[y]) b[i]=a[x++];
            else b[i]=a[y++];
        } else {
            if(y>r) b[i]=a[x++];
            else b[i]=a[y++];
        }
    }
    for(int i=l;i<=r;++i) a[i]=b[i];
}
int main() {
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    // sort(a+1,a+1+n);
    merge_sort(1,n);
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
    return 0;
}