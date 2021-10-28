#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n,x;
int ans;
int a[1000005];
int erfen(int l,int r,int num)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(num>a[mid])
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ans=erfen(1,n,x);
	cout<<ans;
	return 0;
}
