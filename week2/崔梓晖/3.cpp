#include <bits/stdc++.h>
using namespace std;
int n,a[100001],r[100001];
void msort(int s,int e)
{
	if(s==e)
	return;
	int mid=(s+e)/2;
	msort(s,mid);
	msort(mid+1,e);
	int i=s;
	int j=mid+1;
	int k=s;
	while(i<=mid&&j<=e)
	{
		if(a[i]<=a[j])
		{
			r[k]=a[i];
			k++;
			i++;
		}
		else if(a[i]>a[j])
		{
			r[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		r[k]=a[i];
		i++;
		k++;
	}
	while(j<=e)
	{
		r[k]=a[j];
		k++;
		j++;
	}
	for(int i=s;i<=e;i++)
	{
		a[i]=r[i];
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	msort(1,n);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
