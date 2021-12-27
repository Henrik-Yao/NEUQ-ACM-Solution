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
struct node {
    int nxt,pre;
}a[_];
int main() {
    int n=read(),m=read(),k=read();
    for(int i=0;i<n;++i) {
        a[i].nxt=(i+1)%n;
        a[i].pre=(i-1+n)%n;
    }
    int now=0;
    for(int i=1;i<=n;) {
        for(int j=1;j<m;++j) now=a[now].pre;
        cout<<now+1<<" ";
        a[a[now].pre].nxt=a[now].nxt;
        a[a[now].nxt].pre=a[now].pre;
        ++i;
        if(i==n+1) break;
        for(int j=1;j<k;++j) now=a[now].nxt;
        cout<<now+1<<" ";
        a[a[now].pre].nxt=a[now].nxt;
        a[a[now].nxt].pre=a[now].pre;
        ++i;
    }
    return 0;
}
