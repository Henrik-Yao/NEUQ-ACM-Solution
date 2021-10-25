#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,sum=0;
	cin>>n>>m;
	int a[n],b[m];
	int d[m];
	string c[n];
	
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(long long i=0;i<m;i++)
	{
		cin>>b[i]>>d[i];
	}
	for(long long i=0;i<m;i++)
	{
		if((b[i]==1&&a[sum]==1)||(b[i]==0&&a[sum]==0))
		{
			sum-=d[i];
			sum=sum%n;
			if(sum<0) sum+=n;
		}
		else
		{
			 sum+=d[i];
			 sum%=n;
			if(sum<0) sum+=n;
		}
	}
	cout<<c[sum];
	return 0;
}