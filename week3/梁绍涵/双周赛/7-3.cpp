#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	long long ans=1;
	while(cin>>n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=3;
		}
		cout<<ans-1<<endl;
	}
}

