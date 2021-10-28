#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
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

int n,a[maxn],c[maxn],b[maxn],ans;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int a)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		c[i]=c[i]+a;
	}
}

int ask(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	{
		ans+=c[i];
	}
	return ans;
}

signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+n,a[i])-b;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=ask(n)-ask(a[i]);
		add(a[i],1);
	}
	cout<<ans;
	return 0;
}
