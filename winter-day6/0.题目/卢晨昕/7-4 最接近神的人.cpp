#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
ll ans;
int a[500005];
int w[500005];
void mergesort(int x[],int l,int mid,int r)
{
	int len=r-l+1;
	int left=l;
	int right=mid+1;
	int i=0;
	while(left<=mid&&right<=r)
	{
		if(x[left]<=x[right])
		{
			w[++i]=x[left++];
		}
		else
		{
			w[++i]=x[right++];
			ans+=mid-left+1;
		}
	}
	while(left<=mid)
	{
		w[++i]=x[left++];
	}
	while(right<=r)
	{
		w[++i]=x[right++];
	}
	for(int j=1;j<=len;j++)
	{
		x[l+j-1]=w[j];
	}
	return;
}
void msort(int x[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	msort(x,l,mid);
	msort(x,mid+1,r);
	mergesort(x,l,mid,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	msort(a,1,n);
	cout<<ans;
	return 0;
}

