#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 10555
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

long long f[maxn];
int n,aa;

int main()
{
	f[1]=1;f[2]=1;
	for(int i=3;i<=500;i++)
	f[i]=f[i-2]+f[i-1];
	f[1]=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		cout<<f[aa]<<endl; 
	}
	return 0;
}
