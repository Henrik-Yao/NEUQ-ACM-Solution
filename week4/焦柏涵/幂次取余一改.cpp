#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,sum=1;
ll powmod(ll a,ll b)
{
	if(b==0) return sum;
	if(b%2==1) sum=(sum*a)%c;
	a=(a*a)%c;
	powmod(a,b>>=1);
}
int main()
{
	ll t,a,b;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		sum=1;
		cin>>a>>b>>c;
		cout<<powmod(a,b)<<endl;
	}
	return 0;
}
