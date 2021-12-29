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

int n,m,aa,bb,cc,f[1105][1005],pre[1005],c[1005],cnt;
int a[1005][1005];

signed main()
{
	n=read();m=read();
	memset(a,-1,sizeof(a));
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<m;i++)
	{
		aa=read();bb=read();cc=read();
		f[aa][bb]=cc;a[aa][bb]=cc;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	for(int k=0;k<n;k++)
	{
		if(i==k||i==j||j==k) continue;
		if(f[j][k]>f[j][i]+f[i][k])
		{
			f[j][k]=f[j][i]+f[i][k];
			pre[k]=i;pre[i]=j;
		}
	}
	for(int i=1;i<=2;i++)
	{
		aa=read();bb=read();int to=f[aa][bb];
		if(to>1e9) to=-1;
		if(aa==bb) to=0;
		printf("%d",aa);
		while(1)
		{
			int pd=0;
			for(int j=0;j<n;j++)
			if(f[aa][j]+f[j][bb]==f[aa][bb]&&a[aa][j]!=-1)
			{
				aa=j;
				printf("->%d",aa);
				pd=1;
				break;
			}
			if(pd==0) break;
		}
		printf("->%d:%d\n",bb,to);
	}
	int ma=0;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		if(f[i][j]>1e9) continue;
		if(f[i][j]>ma)
		{
			aa=i;bb=j;
			ma=f[i][j];
		}
	}
	printf("%d",aa);int to=f[aa][bb];
	while(1)
	{
		int pd=0;
		for(int j=0;j<n;j++)
		if(f[aa][j]+f[j][bb]==f[aa][bb]&&a[aa][j]!=-1)
		{
			aa=j;
			printf("->%d",aa);
			pd=1;
			break;
		}
		if(pd==0) break;
	}
	printf("->%d:%d\n",bb,to);
	return 0;
}
