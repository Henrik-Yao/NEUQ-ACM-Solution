#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int t[1001000];
long long ans=0,n;
void mergesort(int arr[],int l,int mid,int r)
{
	int i=l,li=l,ri=mid+1;
	while(li<=mid&&ri<=r)
	{
		if(arr[li]<=arr[ri])
		{
			t[i++]=arr[li++];
		}
		else
		{
			t[i++]=arr[ri++];
			ans+=mid-li+1;
		}
		
	}
	while(li<=mid)
	{
		t[i++]=arr[li++];
	}
	while(ri<=r)
	{
		t[i++]=arr[ri++];
	}
	for(int j=l;j<=r;j++)
	{
		arr[j]=t[j];
	}
}
void merge(int arr[],int l,int r)
{
	if(l==r){return;}
	int mid=(l+r)/2;
	merge(arr,l,mid);
	merge(arr,mid+1,r);
	mergesort(arr,l,mid,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	merge(a,1,n);
	cout<<ans;
	return 0;
	
}
