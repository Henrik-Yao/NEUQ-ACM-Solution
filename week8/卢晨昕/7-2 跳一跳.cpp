#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[1000005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i==n)break;
		if(i+a[i]>=n)
		{
			ans++;
			break;
		}
		int maxx=0;
		int maxn=i+a[i];
		for(int j=a[i];j>=1;j--)
		{
			if(a[i+j]>maxx)
			{
				maxx=a[i+j];
				maxn=i+j;
			}
		}
		for(int j=maxn;j<=i+a[i];j++)
		{
			if(j+a[j]>maxx)
			{
				maxx=j+a[j];
				maxn=j;
			}
		}
		i=maxn-1;
		ans++;
	}
	cout<<ans;
	return 0;
}
