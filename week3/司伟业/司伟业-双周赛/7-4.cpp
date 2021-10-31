#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1005
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

int n,aa; 
long long f[maxn];

long long qpow(long long a,int b)
{
	long long ans=1;
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}

signed main()
{
	memset(f,0x3f,sizeof(f));
	f[1]=1;
	for(int i=2;i<=100;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(qpow(2,j)>=f[i]) break;
			f[i]=min(f[i],f[i-j]*2+qpow(2,j)-1);
		}
	}
	while(~scanf("%d",&aa))
	{
		cout<<f[aa]<<endl;
	}
	return 0;
}
