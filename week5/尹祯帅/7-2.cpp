#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long  n;
	cin>>n;
	long long shu;
	while(n--)
	{
		cin>>shu;
		bool ju=0;
		for(long long i=2;i<=sqrt(shu);i++)
		{
			if(shu%i==0) 
			{
				ju=1;
				break; 
			} 
		}
		if(ju==0) 
		{
			cout<<1<<'\n';
			continue;
		}
		if(shu%2==0)
		{
			cout<<2<<'\n';
			continue;
		}
		shu-=2;
		for(long long i=2;i<=sqrt(shu);i++)
		{
			if(shu%i==0) 
			{
				ju=0;
				break; 
			} 
		}
		if(ju) 
		{
			cout<<2<<'\n';
			continue;
		}
		cout<<3<<'\n';
	}
	return 0;
}