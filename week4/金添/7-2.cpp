#include <bits/stdc++.h>
using namespace std;
long long ans(long long n)
{
	if(n==1)
	return 0;
	else if(n==2)
	return 1;
	else if(n==3)
	return 2;
	else
	return ans(n-1)+ans(n-2); 
}
int main()
{
	int n;
	long long m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		if(i==n)
		cout<<ans(m);
		else
		cout<<ans(m)<<endl;
	}
	return 0;
}
