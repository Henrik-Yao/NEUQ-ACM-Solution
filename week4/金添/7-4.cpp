#include <bits/stdc++.h>
using namespace std;
long long fastpower(long long a,long long b,long long c)
{
	long long ans=1;
	while(b)
	{
		ans%=c;
		if(b&1)
		ans=(ans*a)%c;
	    b/=2;
	    a=(a*a)%c; 
	}
	return ans;
}
int main()
{
	long long n,a,b,c;
	cin>>n;
	while(cin>>a>>b>>c)
	{
		cout<<fastpower(a,b,c)<<endl;
	}

	return 0;
}
