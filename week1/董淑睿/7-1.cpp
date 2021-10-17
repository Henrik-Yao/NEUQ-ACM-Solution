#include <bits/stdc++.h>
using namespace std;
char s[60000],t[101];
int main() {
    int gs,n;cin>>gs>>s+1;
    n=strlen(s+1);
    while(gs-->0) {
        cin>>t+1;
        int len=strlen(t+1),ans=0;
        for(int i=1;i<=n;++i) {
            int flag=1;
            for(int j=1;j<=len;++j) {
                if(s[i+j-1]!=t[j]) {
                    flag=0;break;
                }
            }
            ans+=flag;
        }
        cout<<ans;
        if(t!=0) cout<<"\n";
    }
    return 0;
}