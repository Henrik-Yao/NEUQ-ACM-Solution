#include <bits/stdc++.h>
using namespace std;
const int _=2e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m,a[_];
bool check(int mid) {
    int las=1,now=1;
    for(int i=2;i<=n;++i) {
        // cout<<a[i]<<" "<<a[las]<<">\n";
        if(a[i]-a[las]>=mid) {
            las=i;
            now++;
            // cout<<las<<"!\n";
        }
    }
    return now>=m;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+1+n);
    // cout<<check(3);return 0;
    int l=0,r=0x3f3f3f3f,ans=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
} 