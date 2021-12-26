#include<iostream>
#include<cstdio>
#include<string>
#define int long long
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
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

int n,m,q,f[maxn],aa,bb,vis[maxn],ans;

int fi(int x)
{
	if(x!=f[x]) f[x]=fi(f[x]);
	return f[x];
}

signed main()
{
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		if(fi(aa)!=fi(bb))
		{
			f[fi(aa)]=fi(bb);
		}
	}
	for(int i=1;i<=q;i++)
	{
		aa=read();bb=read();
		if(fi(aa)==fi(bb))
		puts("In the same gang.");
		else puts("In different gangs.");
	}
	for(int i=1;i<=n;i++)
	if(vis[fi(i)]==0) {
		vis[fi(i)]=1;
		ans++;
	}
	cout<<ans;
	return 0;
}
