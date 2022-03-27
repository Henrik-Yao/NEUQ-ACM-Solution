#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 10005
#define int long long
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

int f[maxn],n;

signed main()
{
	f[1]=1;f[2]=2;f[3]=4;
	for(int i=4;i<=50;i++)
	f[i]=f[i-3]+f[i-2]+f[i-1];
	while(cin>>n)
	{
		cout<<f[n]<<endl;
	}
}

