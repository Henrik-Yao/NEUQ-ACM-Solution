#include<bits/stdc++.h>
using namespace std;
long long c;
long long quickmod(long long a, long long b, long long c)
{
	if(b<=1)
	return a%c;
	if(b%2==1)
	return a%c*(quickmod((a%c)*(a%c),b/2,c)%c);
	else
	return quickmod((a%c)*(a%c),b/2,c)%c;
}
int main()
{
	long long t,a,b;
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		cout<<quickmod(a,b,c)%c<<endl;
	}
}
