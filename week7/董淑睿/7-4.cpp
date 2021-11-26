#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+710;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,a[_],f[_];
int lowbit(int x) {
    return x&-x;
}
int add(int x,int pos) {
    for(int i=pos;i<=50000;i+=lowbit(i))
        f[i]=max(f[i],x);
}
int query(int pos) {
    int ans=0;
    for(int i=pos;i>0;i-=lowbit(i)) {
        ans=max(ans,f[i]);
    }
    return ans;
}
int main(){
    int T=read();
    while(T-->0) {
        n=read();
        for(int i=1;i<=50000;++i) f[i]=0;
        for(int i=1;i<=n;++i) {
            // 29935
            a[i]=read();
//             if(a[i]==29935) cout<<"nb";
            a[i]+=2;
        }
        int ans=0;
        for(int i=1;i<=n;++i) {
            int tmp=query(a[i]-1)+1;
            add(tmp,a[i]);
            ans=max(ans,tmp);
        }
        cout<<ans<<"\n";
        if(T) cout<<"\n";
    }
    return 0;
}