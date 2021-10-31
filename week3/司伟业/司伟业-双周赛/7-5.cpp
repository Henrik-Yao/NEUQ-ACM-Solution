#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 105
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

int t,n,m,l1,l2;
int a[maxn],b[maxn],c[maxn<<1];

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		m=read();
		for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
		int l1=1;l2=1;
		for(int i=1;i<=n+m;i++)
		{
			if(l1>n)
			{
				c[i]=b[l2];l2++;
			}
			else if(l2>m)
			{
				c[i]=a[l1];l1++;
			}
			else if(a[l1]>=b[l2])
			{
				c[i]=b[l2];l2++;
			}
			else if(a[l1]<b[l2])
			{
				c[i]=a[l1];l1++;
			}
			if(i==1) printf("%d",c[i]);
			else printf(" %d",c[i]);
		}
		puts("");
	}
	return 0;
}
