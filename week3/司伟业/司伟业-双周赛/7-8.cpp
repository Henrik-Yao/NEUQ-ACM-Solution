#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
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

int n,m;
int a[maxn];

int main()
{
	n=read();m=read();int l=1,r=n;
	for(int i=1;i<=n;i++)
	a[i]=read();
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=m)
		{
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
