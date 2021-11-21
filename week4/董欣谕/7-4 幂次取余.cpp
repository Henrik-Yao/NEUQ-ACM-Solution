#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qsm(ll a,ll b,ll c) {
	ll res=1,temp=a;
	while (b) {
		if (b&1) res=res*temp%c;
		temp=temp*temp%c;
		b>>=1;
	}
	return res;
}
int main() {
	ll a,b,c;
	int t;
	cin>>t;
	while (t--) {
		cin>>a>>b>>c;
		cout<<qsm(a,b,c)<<endl;
	}
	return 0;
}
