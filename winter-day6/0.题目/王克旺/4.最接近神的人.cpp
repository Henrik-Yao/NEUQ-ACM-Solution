#include<bits/stdc++.h>
using namespace std;
int n,a[500000],b[500000];
long long ans=0;
void mergesort(int l,int r)
{
	if(l==r)
	{
		return;
	}
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}  
	while(j<=r)
	{
		b[k++]=a[j++];
	}
	for(i=l;i<=r;i++)
	{
		a[i]=b[i];
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(0,n-1);
	cout<<ans;
	return 0;
}
