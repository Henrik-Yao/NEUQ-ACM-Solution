#include <bits/stdc++.h>
using namespace std;
long long n,a[1000001],r[1000001],ans=0;
void hebin(int s,int mid,int e)
{
	int p=s;
	int q=mid+1;
	for(int i=s;i<=e;i++)
	{
		if((q>e)||(a[p]<=a[q]&&p<=mid))
		{
			r[i]=a[p];
			p++;
		}
		else
		{
			r[i]=a[q];
			q++;
			ans=ans+mid-p+1;
		}
	}
	for(int i=s;i<=e;i++)
	{
		a[i]=r[i];
	}
}
void msort(int s,int e)
{
	if(s==e)
	return;
	int mid=(s+e)/2;
	msort(s,mid);
	msort(mid+1,e);
	hebin(s,mid,e);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	msort(1,n);
	cout<<ans;
	return 0;
}

