#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int _=1e6+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
ll A[100]={0,1};
ll f(int n) {return (1ll<<n)-1;}
ll F(int n) {
	if(A[n]) return A[n];
	ll ans=(1ull<<60);
	for(int i=1;i<=min(n,60);++i)
		ans=min(ans,f(i)+2*F(n-i));
	A[n]=ans;
	return A[n];
}
int main() {
	int n;
	while(cin>>n) cout<<F(n)<<"\n";
	return 0;
}