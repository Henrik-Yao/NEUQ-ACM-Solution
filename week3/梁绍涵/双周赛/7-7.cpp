#include<bits/stdc++.h>
using namespace std;
int a[1000010],temp[1000010];
long long ans=0;
void mergesort(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int k=0;
	int left=l,right=mid+1;
	while(left<=mid&&right<=r)
	{
		if(a[left]<=a[right]) temp[k++]=a[left++];
		else
		{
			temp[k++]=a[right++];
			ans+=mid+1-left;
		}
	}
	while(left<=mid) temp[k++]=a[left++];
	while(right<=r) temp[k++]=a[right++];
	int x=0;
	for(int i=l;i<=r;i++)
	{
		a[i]=temp[x];
		x++;	
	}  
}
int main()
{
	int n;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(0,n-1);
	cout<<ans;
}
