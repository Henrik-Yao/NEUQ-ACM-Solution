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

int n,m,a[maxn],s[maxn],ans;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) s[i]=a[i+1]-a[i];
	sort(s+1,s+n,cmp);
	for(int i=m;i<n;i++) ans+=s[i]-1;
	ans+=n;
	cout<<ans;
	return 0;
}
