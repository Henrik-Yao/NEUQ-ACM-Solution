#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int t;
int m,n;
int a[505];
void merge(int arr[],int l,int mid,int r)
{
	int len=r-l+1;
	int w[505];
	int left=l;
	int right=mid+1;
	int i=0;
	while(left<=mid&&right<=r)
	{
		if(arr[left]<=arr[right])
		{
			w[++i]=arr[left++];
		}
		else
		{
			w[++i]=arr[right++];
		}
	}
	while(left<=mid)
	{
		w[++i]=arr[left++];
	}
	while(right<=r)
	{
		w[++i]=arr[right++];
	}
	for(int j=1;j<=len;j++)
	{
		arr[j+l-1]=w[j];
	}
	return;
}
void mergesort(int arr[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	merge(arr,l,mid,r);
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m;
		for(int i=1;i<=m;i++)cin>>a[i];
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[m+i];
		mergesort(a,1,m+n);
		for(int i=1;i<=m+n-1;i++)cout<<a[i]<<" ";
		cout<<a[m+n]<<endl;
	}
	return 0;
}
