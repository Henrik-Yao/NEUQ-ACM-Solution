#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100],maxx=101,num=0,pd[100];
	cin>>n;
	memset(pd,0,sizeof(pd));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<maxx)
		{
			if(a[i]!=1)
			cout<<a[i]<<" ";
			else if(a[i]==1)
			{
				cout<<a[i];
			}
			maxx=a[i];
			pd[i]=1;
			num++;
		}
	}
	cout<<endl;
	int ans=1;
	while(num<n)
	{
		ans++;
		int x=101;
		for(int i=1;i<=n;i++)
		{
			if(pd[i]==0&&a[i]<x)
			{
					x=a[i];
					pd[i]=1;
					num++;
			}
	    }
	}
	cout<<ans;
	return 0;
} 

