#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n;
int a[1000005];
int w[1000005];
long long ans;
int maxn=0;
void merge(int arr[],int l,int mid,int r)
{
	int len=r-l+1;
	int i=0,left=l,right=mid+1;
	while(left<=mid&&right<=r)
	{
		if(arr[left]<=a[right])
		{
			w[++i]=a[left++];
		}
		else
		{
			w[++i]=a[right++];
			ans+=mid-left+1;
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
		arr[l+j-1]=w[j];
	}
	return;
}
void msort(int arr[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	msort(arr,l,mid);
	msort(arr,mid+1,r);
	merge(arr,l,mid,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	msort(a,1,n);
	cout<<ans;
	return 0;
}
