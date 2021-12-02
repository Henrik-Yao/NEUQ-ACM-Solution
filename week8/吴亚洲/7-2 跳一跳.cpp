#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<n;)
	{
		if(i+a[i]>=n)
		{
			cout<<cnt+1;
			return 0;
		}
		int _max=0,k;
		for(int j=1;j<=a[i];j++)
		{
			if(i+j+a[i+j]>_max)
			{
				_max=i+j+a[i+j];
				k=i+j;
			}
		}
		i=k;
		cnt++;
	}
	cout<<cnt;
} 
