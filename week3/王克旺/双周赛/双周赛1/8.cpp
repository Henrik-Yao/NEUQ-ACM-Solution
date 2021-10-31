#include<iostream>
using namespace std;
int main()
{
	int m,n,i;
	cin>>n>>m;
	int a[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>=m)
		{
			break;
		}
	}
	if(i==n)
	{
		cout<<n+1;
	}
	else
	{
		cout<<i;
	}
	return 0;
}
