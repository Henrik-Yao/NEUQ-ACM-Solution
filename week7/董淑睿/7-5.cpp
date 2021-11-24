#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=2e5+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int n,c,w[_],v[_],f[_];
int main() {
    while(cin>>n>>c) {
        for(int i=1;i<=n;++i) w[i]=read();        
        for(int i=1;i<=n;++i) v[i]=read();
        for(int i=1;i<=c;++i) f[i]=0;
        int ans=0;
        for(int i=1;i<=n;++i) {
            for(int j=c;j>=1;--j) {
                if(j-w[i]>=0) f[j]=max(f[j],f[j-w[i]]+v[i]);
                ans=max(ans,f[j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}