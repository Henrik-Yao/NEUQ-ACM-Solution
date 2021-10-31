#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,ans,a[1000010];
void sortpai(int l,int mid,int r)
{
	int m=mid-l+1;
	int n=r-mid;
	int a1[m+1];int a2[n+1];
	for(int i=1;i<=m;i++)
	a1[i]=a[l+i-1];
	for(int i=1;i<=n;i++)
	a2[i]=a[mid+i];
	int i=1,j=1,k=l;
	while(i<=m && j<=n)
	{
		if(a1[i]<=a2[j])a[k++]=a1[i++];
		else a[k++]=a2[j++],ans=ans+m-i+1;
	}
	while(i<=m)
	a[k++]=a1[i++];
	while(j<=n)
	a[k++]=a2[j++];
}
void sortfen(int l,int r)
{
	while(l<r)
	{
	int mid=(l+r)/2;
	sortfen(l,mid);sortfen(mid+1,r);
	sortpai(l,mid,r);
	return;
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=read();
	sortfen(1,n);
	cout<<ans;
	return 0;
}
