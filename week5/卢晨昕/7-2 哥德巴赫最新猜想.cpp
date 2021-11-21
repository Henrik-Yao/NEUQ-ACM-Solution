#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
bool prime(ll x)
{
	for(ll i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		if(a%2==0)
		{
			if(i!=n)cout<<"2"<<endl;
			else cout<<"2";
		}
		else if(prime(a))
		{
			if(i!=n)cout<<"1"<<endl;
			else cout<<"1";
		}
		else
		{
			if(prime(a-2))
			{
				if(i!=n)cout<<"2"<<endl;
			    else cout<<"2";
			}
			else
			{
				if(i!=n)cout<<"3"<<endl;
			    else cout<<"3";
			}
		}
	}
	return 0;
}
