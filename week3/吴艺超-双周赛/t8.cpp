#include<bits/stdc++.h>
#define ll long long
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
int n,m;
struct ax{
	int zhi;
	int wei;
}a[1000005];
void sortpai(int l,int mid,int r)
{
	int m=mid-l+1;
	int n=r-mid;
	ax a1[m+1];ax a2[n+1];
	for(int i=1;i<=m;i++)
	a1[i].zhi=a[l+i-1].zhi,a1[i].wei=a[l+i-1].wei;
	for(int i=1;i<=n;i++)
	a2[i].zhi=a[mid+i].zhi,a2[i].wei=a[mid+i].wei;
	int i=1,j=1,k=l;
	while(i<=m && j<=n)
	{
		if(a1[i].zhi<=a2[j].zhi)a[k].zhi=a1[i].zhi,a[k++].wei=a1[i++].wei;
		else a[k].zhi=a2[j].zhi,a[k++].wei=a2[j++].wei;
	}
	while(i<=m)
	a[k].zhi=a1[i].zhi,a[k++].wei=a1[i++].wei;
	while(j<=n)
	a[k].zhi=a2[j].zhi,a[k++].wei=a2[j++].wei;
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
int main()
{
	cin>>n>>m;int flag=1;
	for(int i=1;i<=n;i++)
	{
	a[i].zhi=read(),a[i].wei=i;
	if(a[i].zhi>=m)
	flag=0;
	}
	if(flag==1)
	{
		cout<<n+1;
		return 0;
	}
	sortfen(1,n);
	for(int i=1;i<=n;i++)
	{
		if(a[i].zhi>=m)
		{
			cout<<a[i].wei;
			return 0;
		}
	}
	return 0;
}
