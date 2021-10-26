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
char s[10];
string ans[1000000];
int n,a[10],vis[10],js;
void f(int now) {
	if(now==n+1) {
		++js;
		for(int i=1;i<=n;++i) {
			ans[js]+=s[a[i]];
		}
		return;
	}
	for(int i=1;i<=n;++i) {
		if(!vis[i]) {
			vis[i]=1;
			a[now]=i;
			f(now+1);
			vis[i]=0;
		}
	}
}
int main() {
	cin>>(s+1);
	n=strlen(s+1);
	f(1);
	sort(ans+1,ans+1+js);
	for(int i=1;i<=js;++i) {
		while(ans[i]==ans[i+1]&&i+1<=n) i++; 
		cout<<ans[i]<<"\n";
	}
	return 0;
}