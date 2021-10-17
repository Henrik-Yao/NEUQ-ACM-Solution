#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define int long long
#define maxn 100005
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

int n,m,aa,bb,pre;
int a[maxn];
char c[maxn][15];

signed main()
{
	n=read();m=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read();scanf("%s",c[i]);
	}
	pre=0;
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		if(aa==1)//you
		{
			if(a[pre]==1)//wai
			{
				pre=((pre-bb)%n+n)%n;
			}
			else if(a[pre]==0)//nei
			{
				pre=(pre+bb)%n;
			}
		}
		if(aa==0)//zuo
		{
			if(a[pre]==1)//wai
			{
				pre=(pre+bb)%n;
			}
			else if(a[pre]==0)//nei
			{
				pre=((pre-bb)%n+n)%n;
			}
		}
	}
	printf("%s\n",c[pre]);
    return 0;
}
