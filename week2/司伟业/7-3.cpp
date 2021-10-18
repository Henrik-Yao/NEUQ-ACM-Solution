#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int n,a[maxn],b[maxn];

void guibing(int l,int r)
{
	if(r==l) return;
	int mid=(l+r)/2;
	guibing(l,mid);guibing(mid+1,r);
	int l1=l,l2=mid+1;
	for(int i=l;i<=r;i++)
	{
		if(l1>mid)
		{
			b[i]=a[l2];l2++;
		}
		else if(l2>r)
		{
			b[i]=a[l1];l1++;
		}
		else if(a[l1]<a[l2])
		{
			b[i]=a[l1];l1++;
		}
		else if(a[l1]>=a[l2])
		{
			b[i]=a[l2];l2++;
		}
	}
	for(int i=l;i<=r;i++) a[i]=b[i];
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	guibing(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
