#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,p,ans,t;
	cin>>t;
	while(t--)
	{
	cin>>a>>b>>p;
	ans=1;
	while(b>0)
	{
		if(b%2!=0)
		{
			ans=ans*a%p;
		}
		a=a*a%p;
		b=b/2;
	}
	cout<<ans<<endl;
    }
	return 0;
}
