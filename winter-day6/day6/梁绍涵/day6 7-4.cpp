#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;int a[1000100],ans[1000100],cnt=0;
void merge(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	int l1=l,l2=mid+1,l3=l;
	while(l1<=mid&&l2<=r)
	{
		if(a[l1]<=a[l2])
		{
			ans[l3++]=a[l1++];
		}
		else
		{
			ans[l3++]=a[l2++];
			cnt+=mid-l1+1;
		}
	}
	while(l1<=mid)
	{
		ans[l3++]=a[l1++];
	}
	while(l2<=r)
	{
		ans[l3++]=a[l2++];
	}
	for(int i=l3; i<=r; i++) a[i]=ans[i];
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	merge(1,n);
	cout<<cnt;
}
