#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll s=0;
	ll a[n+1]={};
	for(ll i=0;i<n;i++)
	{
		if(i==0) a[i]=1;
		else if(n%i==0)
		{
			for(ll j=0;j<i;j++)
		 {
		 	if(j==0) a[i]=a[i]+a[j];
			else if(i%j==0) a[i]=a[i]+a[j];
		 }
		}
		s=s+a[i];
	}
	cout<<s;
    return 0;
}
