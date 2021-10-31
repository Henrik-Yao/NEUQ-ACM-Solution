#include<bits/stdc++.h>
using namespace std;
int a[1000000],temp[1000000];
void he(int l,int mid,int r,int a[])
{
	int i=l,j=mid+1,k=1;
	while(i<=mid&&j<=r)
	{
		if(a[i]>a[j])
		temp[k++]=a[j++];
		else
		temp[k++]=a[i++];
	}
	while(i<=mid)
	temp[k++]=a[i++];
	while(j<=r)
	temp[k++]=a[j++];
	for(int m=1;m<=k-1;m++,l++)
	a[l]=temp[m];
}
void fen(int l,int r,int a[])
{
	if(l>=r)
	return ;
	else
	{
		int mid=(l+r)/2;
		fen(l,mid,a);
		fen(mid+1,r,a);
		he(l,mid,r,a);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	fen(1,n,a);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<""; 
	return 0;
}
