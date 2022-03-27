#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		long long power,base,mod;
		cin>>base>>power>>mod;
		long long ans=1;
		while(power) 
		{
			if(power&1)
			{
				ans=ans*base%mod;	
			} 
			power>>=1;
			base=(base*base) %mod;
		}
		cout<<ans<<endl;
	}
		return 0;
}

