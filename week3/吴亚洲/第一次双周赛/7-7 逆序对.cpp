#include<bits/stdc++.h>
using namespace std;
long long a[1000001],temp[1000001];
long long ans=0,k=1;
void he(int l,int r,int mid)
{
	k=1;
	int i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]>a[j])
		{
			temp[k++]=a[j++];
			ans+=(mid-i+1);
		}
		else
		temp[k++]=a[i++];
	}
	while(i<=mid)
	temp[k++]=a[i++];
	while(j<=r)
	temp[k++]=a[j++];
	for(int m=1;m<k;m++)
	a[m+l-1]=temp[m];
}
void fen(int l,int r)
{
	if(l>=r)
	return;
	int mid=(l+r)/2;
	fen(l,mid);
	fen(mid+1,r);
	he(l,r,mid);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	fen(1,n);
	cout<<ans;
}
