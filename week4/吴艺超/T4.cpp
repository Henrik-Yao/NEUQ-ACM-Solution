#include<bits/stdc++.h>
#define ll long long
#define N 10000
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
ll ksm(ll x,ll y,ll p)
{
	ll res=1;
	for(;y;y>>=1,x=x*x%p)
	{
		if(y&1)res=res*x%p;
	}
	return res;
}
int t;
int main()
{
	t=read();
	while(t--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<ksm(a,b,c)%c<<endl;
	}
	return 0;
}
