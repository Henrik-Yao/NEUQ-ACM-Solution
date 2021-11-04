#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
ll speedpow(ll a,ll b,ll mo)
{
	ll ans=1;
	ll ca=a;
	for(;b;b>>=1)
	{
		if(b&1)ans=ans*ca%mo;
		ca=ca*ca%mo;
	}
	return ans;
}
int t;
int main()
{
	cin>>t;
	while(t--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<speedpow(a,b,c)<<endl;
	}
	return 0;
}
