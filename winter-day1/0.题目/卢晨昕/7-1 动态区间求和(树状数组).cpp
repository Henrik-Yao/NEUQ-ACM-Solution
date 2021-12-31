#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
ll a[1000005];
ll c[1000005];

void add(int x,int y)
{
	for(;x<=n;x+=x&-x)c[x]+=y;
}
ll ask(int x)
{
	ll ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)add(i,a[i]);
	for(int i=1;i<=q;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)add(b,c);
		else cout<<ask(c)-ask(b-1)<<endl;
	}
	return 0;
}
