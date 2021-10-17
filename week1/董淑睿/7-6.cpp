#include <bits/stdc++.h>
using namespace std;
const int oo=0x3f3f3f3f;
int main() {
    int n,T,ans=-oo;
    cin>>n>>T;
    for(int i=1;i<=n;++i) {
        int v,t;
        cin>>v>>t;
        if(t>T) {
            ans=max(ans,v-(t-T));
        } else {
            ans=max(ans,v);
        }
    }
    cout<<ans;
    return 0;
}