#include <bits/stdc++.h>
using namespace std;
const int _=1e6+7;
int n,a[_],be[_],en[_],t[_];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        be[i]=be[i-1]+(t[a[i]]++==0);        
    memset(t,0,sizeof(t));
    for(int i=n;i>=1;--i)
        en[i]=en[i+1]+(t[a[i]]++==0);
    int ans=0;
    for(int i=1;i<n;++i)
        ans=max(ans,be[i]+en[i+1]);
    cout<<ans;
    return 0;
}