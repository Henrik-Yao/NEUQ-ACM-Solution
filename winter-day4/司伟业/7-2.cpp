#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
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

int n,m,aa,bb,cc,f[1105][1005];

signed main()
{
	while(cin>>n>>m)
	{
		memset(f,0x3f,sizeof(f));
		for(int i=0;i<n;i++)
		{
			aa=read();bb=read();
			for(int j=1;j<=bb;j++)
			{
				cc=read();
				f[aa][cc]=1;
			}
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
		{
			if(i==k||i==j||j==k) continue;
			f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
		}
		for(int i=1;i<=m;i++)
		{
			aa=read();bb=read();
			if(f[aa][bb]>1e9) puts("connection impossible");
			else cout<<f[aa][bb]<<endl;
		}
	}
	return 0;
}
